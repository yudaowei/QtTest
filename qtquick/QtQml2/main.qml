import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.1
import QtQuick 2.13
import QtQml 2.13
import QtGraphicalEffects 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.13
import "./controls" as MyControl
import an.qt.ColorMaker 1.0
import an.qt.ImageProcessor 1.0
Window {
    visible: true
    width: 1920
    height: 1040
    color: "#ccffffff"
    title: qsTr("hello quick")
    Rectangle{
        id:signalAndSlot;
        width: 320;
        height: 240;
        anchors.left: parent.left;
        anchors.top: parent.top;
        border.color: "black";
        signal colorChanged(color clr);//自定义信号
        function text2ColorChange(clr){//自定义槽函数
            text2.color = clr;
        }
        function text3ColorChange(){
            text3.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
        }
        Text{
            id:text1;
            anchors.left: parent.left;
            anchors.leftMargin: 10;
            anchors.top: parent.top;
            anchors.topMargin: 20;
            font.pixelSize: 40;
            text:qsTr("text1");
        }
        Text {
            id: text2;
            text: qsTr("text2");
            anchors.left: text1.right;
            anchors.top: text1.top;
            font.pixelSize: 40;
        }
        Text{
            id:text3;
            text:qsTr("text3");
            anchors.left: text2.right;
            anchors.top:text2.top;
            font.pixelSize: 40;
        }
        Button{
            id:changeButton;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 25;
            text:qsTr("changeColor");
            onClicked: {//emit signal
                signalAndSlot.colorChanged(Qt.rgba(Math.random(), Math.random(), Math.random(), 1));
            }
        }
        Component.onCompleted: {
            changeButton.onClicked.connect(text3ColorChange);//connect
        }
        Connections{
            target: signalAndSlot;
            onColorChanged:{
                signalAndSlot.text2ColorChange(clr);
            }
        }

        Connections{
            target: changeButton;
            onClicked:{
                text1.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            }
        }
    }
    Rectangle{
        id:mouseEvent;
        width: 320;
        height: 240;
        border.color: "black";
        anchors.left:signalAndSlot.right;
        anchors.top:signalAndSlot.top;
        RadialGradient{
            id:radial;
            anchors.fill: parent;
            gradient: Gradient{
                GradientStop { position: 0.0; color: "white" }
                GradientStop { position: 0.5; color: "black" }
            }
        }
        MouseArea{
            id:mouseArea;
            anchors.fill: parent;
            hoverEnabled: true;
            propagateComposedEvents: true;
            acceptedButtons: Qt.LeftButton | Qt.RightButton;
            Menu {
                id: contextMenu
                MenuItem {
                    text: qsTr("Quit") ;
                    onTriggered: Qt.quit();
                }
            }
            onClicked: {
                if(mouse.button === Qt.LeftButton ){
                    radial.horizontalOffset = mouseX - mouseEvent.width/2;
                    radial.verticalOffset = mouseY - mouseEvent.height/2;
                    mouse.accepted = true;
                }else if(mouse.button === Qt.RightButton){
                    contextMenu.popup();
                }
            }
            onPositionChanged: {
                if(hoverEnabled == true){
                    radial.horizontalOffset = mouseX - mouseEvent.width/2;
                    radial.verticalOffset = mouseY - mouseEvent.height/2;
                    mouse.accepted = true;
                }
            }
            onDoubleClicked: {
                if(mouse.button === Qt.LeftButton ){
                    hoverEnabled = !hoverEnabled;
                    mouse.accepted = true;
                }
            }
        }
    }
    Rectangle{
        id: keyEvent;
        width: 320;
        height: 240;
        anchors.left: mouseEvent.right;
        anchors.top:mouseEvent.top;
        color: "gray";
        focus: true;
        Keys.forwardTo: [moveText, likeQt];

        Keys.enabled: true;
        Keys.onEscapePressed: {
            Qt.quit();
        }
        Text{
            anchors.centerIn: parent;
            text:" Esc = quit, ctr+G = changColor"
        }

        Text{
            id:moveText;
            x:20;
            y:20;
            width:200;
            height:30;
            focus:true;
            text:"Moving Text";
            color:"blue";
            font.bold: true;
            font.pixelSize: 24;
            Keys.enabled: true;
            Keys.onPressed: {
                if((event.key === Qt.Key_G)&&
                        (event.modifiers === Qt.ControlModifier)){//组合键
                    moveText.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
                }
                switch(event.key){
                case Qt.Key_Up:
                    moveText.y -= 5;
                    break;
                case Qt.Key_Left:
                    moveText.x -= 5;
                    break;
                case Qt.Key_Down:
                    moveText.y += 5;
                    break;
                case Qt.Key_Right:
                    moveText.x += 5;
                    break;
                default:

                    return;
                }
                event.accepted = true;
            }
        }
        CheckBox{
            id:likeQt;
            text:"like Qt Quick";
            anchors.left: parent.left;
            anchors.leftMargin: 10;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 10;
            z:1;
        }
    }
    Rectangle{
        id:timerTest;
        width: 320;
        height: 240;
        anchors.left: keyEvent.right;
        anchors.top: keyEvent.top;
        border.color: "black";
        color:"gray";
        QtObject{
            id:attrs;
            property int counter;
            Component.onCompleted: {
                attrs.counter = 10;
            }
        }
        Label{
            id:countShow;
            anchors.centerIn: parent;
            color:"blue";
            font.pixelSize: 40;
        }
        Timer{
            id:countDown;
            interval: 1000;
            repeat: true;
            triggeredOnStart: true;
            onTriggered: {
                attrs.counter -= 1;
                countShow.text = attrs.counter;
                if(attrs.counter < 0){
                    countDown.stop();
                    countShow.text = qsTr("Clap now");
                }
            }
        }
        Button{
            id:startButton;
            anchors.top:countShow.bottom;
            anchors.topMargin: 10;
            anchors.horizontalCenter: parent.horizontalCenter;
            background: Rectangle{
                radius: 20;
                color: startButton.down ? "#ccc" : "#eee" ;
            }

            text: qsTr("Start");
            onClicked: {
                attrs.counter = 10;
                countDown.start();
            }
        }
    }
    Rectangle{
        id:pinchTest;
        width:320;
        height: 240;
        anchors.left: signalAndSlot.left;
        anchors.top:signalAndSlot.bottom;
        border.color: "black";
        Rectangle{
            width: 60;
            height: 60;
            color:"blue";
            id: transformRect;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.left: parent.left;
            anchors.leftMargin: 25;
            PinchArea{
                anchors.fill: parent;
                pinch.maximumRotation: 90;
                pinch.minimumRotation: 0;
                pinch.maximumScale: 20;
                pinch.minimumScale: 0.2;
                pinch.target: transformRect;
            }
        }
        Rectangle{
            width: 60;
            height: 60;
            color: "blue";
            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: 25;
            PinchArea{
                anchors.fill: parent;
                pinch.maximumRotation: 90;
                pinch.minimumRotation: 0;
                pinch.maximumScale: 20;
                pinch.minimumScale: 0.2;
                onPinchStarted: {
                    pinch.accepted = true;
                }
                onPinchUpdated: {
                    parent.scale *= pinch.scale;
                    parent.rotation += pinch.rotation;
                }
                onPinchFinished: {
                    parent.scale *= pinch.scale;
                    parent.rotation += pinch.rotation;
                }
            }
        }
    }
    Rectangle{
            id:componentTest;
            width: 320;
            height: 240;
            anchors.left: pinchTest.right;
            anchors.top: pinchTest.top;
            border.color: "black";
            color: "gray";
            Text{
                id: coloredText;
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.top:parent.top;
                anchors.topMargin: 4;
                text:qsTr("Hello World!");
                font.pixelSize: 32;
            }
            function setTextColor(clr){
                coloredText.color = clr;
            }
            //直接引用同文件夹下的组件
            ColorPicker{
                id: redColor;
                color:"red";
                anchors.left: parent.left;
                anchors.leftMargin: 4;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 4;

                KeyNavigation.right: blueColor;
                KeyNavigation.tab: blueColor;
                onColorPicked: {
                    coloredText.color = clr;
                }
            }
            ColorPicker{
                id: blueColor;
                color: "blue";
                anchors.left: redColor.right;
                anchors.leftMargin: 4;
                anchors.bottom: redColor.bottom;

                KeyNavigation.right: pinkColor;
                KeyNavigation.left: redColor;
                KeyNavigation.tab: pinkColor;
            }
            ColorPicker{
                id: pinkColor;
                color: "pink";
                anchors.left: blueColor.right;
                anchors.leftMargin: 4;
                anchors.bottom: blueColor.bottom;
                KeyNavigation.left: blueColor;
                KeyNavigation.tab:changeButton;
            }
            Component.onCompleted: {
                blueColor.colorPicked.connect(setTextColor);
                pinkColor.colorPicked.connect(setTextColor);
            }
            //嵌入组件,配合Loader工作
            Component{
                id: colorComponent;
                Rectangle{
                    id: colorPickerCom;
                    width: 50;
                    height: 30;
                    signal colorPicked(color clr);
                    property Item loader;
                    border.width: loader.focus? 2:0;
                    border.color: loader.focus? "#90D750":"#808080";
                    MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                            colorPickerCom.colorPicked(colorPickerCom.color);
                            colorPickerCom.loader.focus = true;
                        }
                    }
                }
            }
            Loader{
                id: redLoader;
                width: 80;
                height: 60;
                anchors.bottom: redColor.top;
                anchors.bottomMargin: 4;
                anchors.left: redColor.left;
                KeyNavigation.tab: blueLoader;
                sourceComponent: colorComponent;
                onLoaded: {
                    item.color = "red";
                    item.loader = redLoader;
                }
            }
            Loader{
                id: blueLoader;
                anchors.left: redLoader.right;
                anchors.leftMargin: 4;
                anchors.bottom: redLoader.bottom;
                KeyNavigation.tab: redColor;
                sourceComponent: colorComponent;
                onLoaded: {
                    item.color = "blue";
                    item.loader = blueLoader;
                }
            }
            Connections{
                target: redLoader.item;
                onColorPicked:{
                    componentTest.setTextColor(clr);
                }
            }
            Connections{
                target: blueLoader.item;
                onColorPicked:{
                    componentTest.setTextColor(clr);
                }
            }
            //Loader动态加载从文件中加载组件(不稳定 onFocusChanged不工作)
            property bool colorPickerShow: false;
            Button{
                id:ctrlButton;
                text: "Show";
                anchors.top: redLoader.top;
                anchors.bottom: blueLoader.top;
                anchors.bottomMargin: 4;
                anchors.right: blueLoader.right;
                anchors.left: blueLoader.left;
                onClicked: {
                    if(componentTest.colorPickerShow){
                        pinkLoader.source = "";
                        componentTest.colorPickerShow = false;
                        ctrlButton.text = "Show";
                    }else{
                        pinkLoader.source = "ColorPicker.qml";
                        pinkLoader.item.colorPicked.connect(componentTest.setTextColor);
                        componentTest.colorPickerShow = true;
                        ctrlButton.text = "Hide";
                    }
                }
            }

            Loader{
                id: pinkLoader;
                width: 80;
                height: 50;
                anchors.left: blueLoader.right;
                anchors.leftMargin: 4;
                anchors.bottom: blueLoader.bottom;
                onFocusChanged: {
                    if(item != null)
                        item.focus = focus;
                }
                onLoaded: {
                    item.color = "pink";
                }
                Connections{
                    target: pinkLoader.item;
                    onColorPicked:{
                        componentTest.setTextColor(clr);
                    }
                }
            }
            //ECMAScrip中创建动态对象 及 销毁对象 destroy()
            //方法一:使用Qt.createComponent(), Component.createObject()
            //方法二:使用Qt.createQmlObject()创建对象
            property int  count: 0;
            property Component component: null;
            property var dynamicObject: new Array;
            Button{
                id:add;
                text:"add";
                anchors.left: parent.left;
                anchors.leftMargin: 4;
                anchors.bottom: redLoader.top;
                anchors.bottomMargin: 4;
                onClicked: {
                    componentTest.createColorPicker(Qt.rgba(Math.random(), Math.random(), Math.random(), 1));
                }
            }
            Button{
                id:del;
                text:"del";
                anchors.left: add.right;
                anchors.leftMargin: 4;
                anchors.top: add.top;
                onClicked: {
                    if(componentTest.dynamicObject.length > 0){
                        var deleted = componentTest.dynamicObject.splice(-1, 1);
                        deleted[0].destroy();
                        componentTest.count--;
                    }
                }
            }

            function createColorPicker(clr){
                if(componentTest.component == null){
                    componentTest.component = Qt.createComponent("ColorPicker.qml");
                }
                var colorPicker_EC;
                if(componentTest.component.status === Component.Ready){
                    colorPicker_EC = componentTest.component.createObject(componentTest,
                                                                          {
                                                                              "color": clr,
                                                                              "anchors.bottom" : add.top,
                                                                              "anchors.bottomMargin":4,
                                                                              "x":componentTest.count *55 + 4
                                                                          });
                    colorPicker_EC.colorPicked.connect(componentTest.setTextColor);
                    componentTest.dynamicObject[componentTest.dynamicObject.length] = colorPicker_EC;
                }
                componentTest.count++;
            }
        }
    Rectangle{
        id:positionerTest;
        width: 320;
        height: 240;
        anchors.left: componentTest.right;
        anchors.top: componentTest.top;
        border.color: "black";
        Text {
            id: showNum;
            font.pixelSize: 32;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top:parent.top;
            anchors.topMargin: 10;
        }
        function showPosition(num){
            showNum.text = num;
        }
        Row{
            id:row;
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            spacing: 4;
            layoutDirection:Qt.RightToLeft;
            ColorPicker{
                color: "red";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"green";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"blue";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"pink";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
        }
        Column{
            id:column;
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            spacing: 4;
            ColorPicker{
                color: "red";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"green";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"blue";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"pink";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }

        }
        Grid{
            id: grid;
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            anchors.bottom: row.top;
            anchors.bottomMargin: 4;
            rows:2;
            columns: 2;
            spacing: 4;
//            padding: 4;
            ColorPicker{
                color: "red";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"green";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"blue";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"pink";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
        }
        Flow{
            anchors.left:column.right;
            anchors.leftMargin: 4;
            anchors.top:column.top;
            anchors.right:grid.left;
            anchors.rightMargin: 4;
            anchors.bottom: row.top;
            anchors.bottomMargin: 4;
            spacing: 4;
            ColorPicker{
                color: "red";
                width: 80;
                height: 20;
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                width: 60;
                height: 60;
                color:"green";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"blue";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
            ColorPicker{
                color:"pink";
                onColorPicked: {
                    positionerTest.showPosition(Positioner.index);
                }
            }
        }
    }
    Rectangle{
        id:layoutTest;
        width: 320;
        height: 240;
        anchors.left: positionerTest.right;
        anchors.top: positionerTest.top;
        border.color: "black";
        Text{
            id: centerText;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top:parent.top;
            anchors.topMargin: 4;
            text:qsTr("A Single Text!");
            font.pixelSize: 32;
        }
        function setTextColor(clr){
            centerText.color = clr;
        }
        GridLayout{
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            width: 300;
            rows:3;
            columns: 3;
            rowSpacing: 4;
            columnSpacing: 4;
            flow:GridLayout.TopToBottom;
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                Layout.rowSpan: 3;
//                Layout.columnSpan: 3;
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                Layout.fillWidth: true;
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
            ColorPicker{
                color:Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                onColorPicked: {
                    layoutTest.setTextColor(clr);
                }
            }
        }
    }
    Rectangle{
        id:commonCtr;
        anchors.left: parent.left;
        anchors.top:pinchTest.bottom;
        border.color: "black";
        width: 960;
        height: 440;
        color:"gray";
        GridLayout{
            anchors.fill: parent;
            rowSpacing: 4;
            columnSpacing: 4;
            columns:9;
            TextInput{
                width: 40;
                autoScroll: true;
                text: qsTr("TextInput");
                font.pixelSize: 20;
                wrapMode: TextInput.WrapAnywhere;
                selectByMouse: true;
                selectedTextColor: "white";
                selectionColor: "pink";
            }
            TextField{
                color:"white";
                width: 50;
                selectByMouse: true;
                font.pixelSize: 20;
                text:qsTr("TextField");
                bottomInset: 0.5
                hoverEnabled: true;
                wrapMode: TextInput.WrapAnywhere;
                background: Rectangle{
                    radius: 8;
                    color:"black";
                    implicitHeight: 24;
                    implicitWidth: 100;
                    border.color: "#333";
                    border.width: 6;
                }
            }
            TextEdit{
                width: 200;
                height: 200;
                text: "<i>TextEdit</i>";
                font.pixelSize: 20;
                selectByMouse: true;
                textFormat: TextEdit.AutoText;
            }
            Rectangle{
                width:50;
                height: 50;
                clip: true;
                ScrollView{//实验中滚动不生效
                    anchors.fill: parent;
                    TextArea{
                        //                    wrapMode: TextInput.WrapAnywhere;
                        property int preContentHeight: 0
                        text:"TextArea";
                        font.pixelSize: 10;
                        selectByMouse: true;
                        background: Rectangle{
                            color: "pink";
                        }
                    }
                }
            }
            //RadioButton在同一个父类会自动互斥
            Control{
                id:radioCtr;
                hoverEnabled : true;
                background: Rectangle{
                    id:radioCtrBack;
                    implicitHeight: 12;
                    implicitWidth: 16;
                    radius: 6;
                    border.color: radioCtr.hovered?"darkblue":"gray";
                    border.width: 1;
                }
                onHoveredChanged: {
                    if(radioCtr.hovered){
                        radioCtrBack.color = "#a9a9a9";
                    }else{
                        radioCtrBack.color = "#f8f8ff";
                    }
                }
            }
            RadioButton{
                text: qsTr("ios");
                background: radioCtr
            }
            RadioButton{
                text: qsTr("Android");
            }
            MyControl.CtrRadioButton{
                text:"miOS";
                font.pixelSize: 20;
            }
            Column{
                id: checkbox;
                ButtonGroup{
                    id:childGroup;
                    exclusive: false;
                    checkState: parentBox.checkState;
                }
                CheckBox{
                    id:parentBox;
                    text:qsTr("Parent");
                    checkState: childGroup.checkState;
                }
                CheckBox {
                    checked: true;
                    text: qsTr("Child 1");
                    leftPadding: indicator.width;
                    ButtonGroup.group: childGroup;
                }
                CheckBox {
                    text: qsTr("Child 2")
                    leftPadding: indicator.width
                    ButtonGroup.group: childGroup
                }
            }
            GroupBox {
                id:parentCheckbox;
                label: CheckBox {
                    id: checkBox
                    checked: true
                    text: qsTr("Synchronize")
                }

                ColumnLayout {
                    anchors.fill: parent
                    enabled: checkBox.checked
                    CheckBox { text: qsTr("E-mail") }
                    CheckBox { text: qsTr("Calendar") }
                    CheckBox { text: qsTr("Contacts") }
                }
            }
            ComboBox {
                id: control
                model: ["First", "Second", "Third","4"]

                delegate: ItemDelegate {
                    width: control.width
                    contentItem: Text {
                        text: modelData
                        color: "black"
                        font: control.font
                        elide: Text.ElideRight
                        verticalAlignment: Text.AlignVCenter
                    }
                    highlighted: control.highlightedIndex === index
                }

                indicator: Canvas {
                    id: canvas
                    x: control.width - width - control.rightPadding
                    y: control.topPadding + (control.availableHeight - height) / 2
                    width: 12
                    height: 8
                    contextType: "2d"

                    Connections {
                        target: control
                        onPressedChanged: canvas.requestPaint()
                    }

                    onPaint: {
                        context.reset();
                        context.moveTo(0, 0);
                        context.lineTo(width, 0);
                        context.lineTo(width / 2, height);
                        context.closePath();
                        context.fillStyle = control.pressed ? "#17a81a" : "#21be2b";
                        context.fill();
                    }
                }

                contentItem: Label {
                    leftPadding: 0
                    rightPadding: control.indicator.width + control.spacing

                    text: control.displayText
                    font: control.font
                    color: control.pressed ? "#17a81a" : "#21be2b"
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: 120
                    implicitHeight: 40
                    border.color: control.pressed ? "#17a81a" : "#21be2b"
                    border.width: control.visualFocus ? 2 : 1
                    radius: 2
                }

                popup: Popup {
                    y: control.height - 1
                    width: control.width
                    implicitHeight: 75
                    padding: 1

                    contentItem: ListView {
                        clip: true
                        implicitHeight: contentHeight
                        model: control.popup.visible ? control.delegateModel : null
                        currentIndex: control.highlightedIndex

                        ScrollIndicator.vertical: ScrollIndicator { }
                    }

                    background: Rectangle {
                        border.color: "#21be2b"
                        color:"gray"
                        radius: 2
                    }
                }
            }
            ProgressBar{
                id:progress;
                Timer{
                    interval: 50;
                    repeat:true;
                    onTriggered: {
                        if(progress.value != 1)
                            progress.value += 0.01;
                        else
                            progress.value = 0;
                    }
                    Component.onCompleted: {
                        running = true;
                    }
                }
                background: Rectangle{
                    color: "white";
                    implicitWidth: 150;
                    implicitHeight: 20;
                    radius: 10;
                }
                contentItem: Item{
                    implicitWidth: 150;
                    implicitHeight: 18;
                    Rectangle{
                        width: progress.visualPosition * parent.width;
                        height: parent.height;
                        radius: 10;
                        color:"pink";
                    }
                }
            }
        }
    }
    Rectangle{
        id:tabView;
        anchors.left: commonCtr.right;
        anchors.top:commonCtr.top;
        anchors.bottom: commonCtr.bottom;
        anchors.right: layoutTest.right;
        border.color:"black";
        color: "gray";
        TabBar {
            id: bar
            TabButton {
                text: qsTr("Home")
                width: implicitWidth;
            }
            TabButton {
                text: qsTr("Discover")
                width: implicitWidth;

            }
            TabButton {
                text: qsTr("Activity")
                width: implicitWidth;

            }
        }
        StackLayout{
            currentIndex: bar.currentIndex;
            anchors.top: bar.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.bottom: parent.bottom;
            Rectangle{
                color:"white";
                Slider{
                    id:mcontrol;
                    anchors.centerIn: parent;
                    snapMode:Slider.SnapOnRelease
                    background: Rectangle {
                        x: mcontrol.leftPadding
                        y: mcontrol.topPadding + mcontrol.availableHeight / 2 - height / 2
                        implicitWidth: 200
                        implicitHeight: 4
                        width: mcontrol.availableWidth
                        height: implicitHeight
                        radius: 2
                        color: "black"

                        Rectangle {
                            width: mcontrol.visualPosition * parent.width
                            height: parent.height
                            color: "pink"
                            radius: 2
                        }
                    }
                    handle: Rectangle {
                        x: mcontrol.leftPadding + mcontrol.visualPosition * (mcontrol.availableWidth - width)
                        y: mcontrol.topPadding + mcontrol.availableHeight / 2 - height / 2
                        implicitWidth: 26
                        implicitHeight: 26
                        opacity: 0.4;
                        radius: 13
                        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
                        border.color: "#bdbebf"
                    }

                }
            }
            Rectangle{
                color:"white";
                Flickable{
                    anchors.fill: parent;
                    width: 150;
                    height: 150;
                    contentWidth: image.width;
                    contentHeight: image.height;
                    Image{
                        id:image;
                        source: "file:/e:/wangyunb/Work_Documents/NorthProject/UI_Source/yu/working/demo/qtquick/QtQml2/20200922112027.png";
                    }
                }
            }
            Rectangle{
                color:"pink";
            }
        }

    }
    Rectangle{
        id: canvasTest;
        border.color: "black";
        width: 320;
        height: 240;
        anchors.left: timerTest.right;
        anchors.top: timerTest.top;
//        anchors.right: parent.right;

        TabBar{
            id: canvasBar;
            TabButton{
                text: "1";
            }
            TabButton{
                text: "2";
            }
            TabButton{
                text: "3";
            }
            TabButton{
                text: "4";
            }
            TabButton{
                text: "5"
            }
        }
        StackLayout{
            currentIndex: canvasBar.currentIndex;
            anchors.top: canvasBar.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.bottom: parent.bottom;
            Rectangle{
                border.color: "black";
                Canvas{
                    id: mycanvas1;
                    anchors.fill: parent;
                    renderTarget: Canvas.FramebufferObject;
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.lineWidth = 2;
                        ctx.strokeStyle = "red";
                        ctx.fillStyle = "blue";
                        ctx.beginPath();
                        ctx.shadowBlur = 20;
                        ctx.shadowColor = "gray";
                        ctx.shadowOffsetX = 10;
                        ctx.shadowOffsetY = 20;
                        ctx.rect(50, 50, 120, 80);
                        ctx.fill();
                        ctx.stroke();
                    }
                }

            }
            Rectangle{
                border.color: "black";
                Canvas{
                    id: mycanvas2;
                    anchors.fill: parent;
//                    renderStrategy: Canvas.Threaded;
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.lineWidth = 2;
                        ctx.strokeStyle = "red";
//                        ctx.shadowBlur = 10;
//                        ctx.shadowColor = "gray";
//                        ctx.shadowOffsetX = 10;
//                        ctx.shadowOffsetY = 20;
                        var gradient = ctx.createLinearGradient(0, 0, 120, 80);
                        gradient.addColorStop(0.0, Qt.rgba(1, 0, 0, 1.0));
                        gradient.addColorStop(1.0, Qt.rgba(0, 0, 1, 1.0));
                        ctx.fillStyle = gradient;
                        ctx.beginPath();
                        ctx.rect(0, 0, 120, 80);
                        ctx.fill();
                        ctx.stroke();
                        ctx.beginPath();
                        ctx.rect(140, 0, 120, 80);
                        ctx.stroke();
//                        ctx.shadowBlur = 0;
                        for(var i=0; i<7; i++){
                            gradient = ctx.createRadialGradient(140 + i*20, 0, 10, 260, 80, 0);
                            if(i%2 == 0){
                                gradient.addColorStop(0.0, Qt.rgba(1, 0, 0, 1.0));
                                gradient.addColorStop(1.0, Qt.rgba(0, 0, 1, 1.0));
                            }
                            ctx.fillStyle = gradient;
                            ctx.fill();
                        }
//                        ctx.shadowBlur = 20;
                        ctx.fillStyle = "gray";
                        ctx.strokeStyle = "black";
                        ctx.beginPath();
                        ctx.translate(140, 0);
                        ctx.moveTo(0,0);
                        ctx.lineTo(0, 80);
                        ctx.lineTo(120, 80);
                        ctx.closePath();
                        ctx.fill();
                        ctx.stroke();
                    }
                }

            }
            Rectangle{
                border.color: "black";
                Canvas{
                    id: mycanvas3;
                    anchors.fill: parent;
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.lineWidth = 2;
                        ctx.strokeStyle = "red";
                        ctx.font = "42px sans-serif";
                        var gradient = ctx.createLinearGradient(0, 0, width, height);
                        gradient.addColorStop(0.0, Qt.rgba(1, 0, 0, 1.0));
                        gradient.addColorStop(1.0, Qt.rgba(0, 0, 1, 1.0));
                        ctx.fillStyle = gradient;
                        ctx.beginPath();
                        ctx.moveTo(4, 4);
                        ctx.bezierCurveTo(0, height-1, width-1, height/2, width/4, height/4);
                        ctx.lineTo(width/2, height/4);
                        ctx.arc(width*5/8, height/4, width/8, Math.PI, 0, false);
                        ctx.ellipse(width*11/16, height/4, width/8, height/4);
                        ctx.lineTo(width/2, height*7/8);
                        ctx.text("Complex Path", width/6, height*7/8);
                        ctx.fill();
                        ctx.stroke();
                    }
                }
            }
            Rectangle{
                border.color: "black";
                Canvas{
                    id: mycanvas4;
                    anchors.fill: parent;
                    property string poster: "file:/e:/wangyunb/Work_Documents/NorthProject/UI_Source/yu/working/demo/qtquick/QtQml2/20200922112027.png";
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.drawImage(poster, 0, 0);
                    }
                    Component.onCompleted: {
                        loadImage(poster);
                    }
                    onImageLoaded: requestPaint();
                }
            }
            Rectangle{
                border.color:"black";
                Canvas{
                    id: mycanvas5;
                    anchors.fill: parent;
                    contextType: "2d";
                    property var im: "file:/e:/wangyunb/Work_Documents/NorthProject/UI_Source/yu/working/demo/qtquick/QtQml2/images/xzq.jpg";
                    onPaint: {
                        context.strokeStyle = "black";
                        context.lineWidth = 2;
                        context.fillStyle = Qt.rgba(0.3,0.5,0.7,0.3);
                        context.save();

                        context.beginPath();
                        context.arc(width/2, height/3, 50,0, Math.PI*2);
                        context.moveTo(width/2, height/3+50);
                        context.lineTo(width/4, height);
                        context.lineTo(width*3/4, height);
                        context.closePath();
                        context.clip();
                        context.drawImage(im, width/4, 0, width/2, height);
                        context.stroke();
                        context.fill();
                        context.restore();
                    }
                    Component.onCompleted: {
                        loadImage(im);
                    }
                    onImageLoaded: requestPaint();
                }
            }
        }
    }
    Rectangle{
        id:qmlCTest;
        border.color: "black";
        anchors.top: canvasTest.bottom;
        anchors.left: layoutTest.right;
        anchors.right: canvasTest.right;
        anchors.bottom: layoutTest.bottom;
        Text{
            id: timeLabel;
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            font.pixelSize: 26;
        }
        ColorMaker{
            id: colorMaker;
            color: Qt.green;
        }
        Rectangle{
            id: colorRec;
            anchors.centerIn: parent;
            width: 50;
            height: 50;
            color: "blue";
        }
        function changeAlgorithm(button, algorithm){
            switch(algorithm){
            case 0:
                button.text = "RandomRGB";
                break;
            case 1:
                button.text = "RandomRed";
                break;
            case 2:
                button.text = "RandomGreen";
                break;
            case 3:
                button.text = "RandomBlue";
                break;
            case 4:
                button.text = "LinearIncrease";
                break;
            }
        }
        Column{
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            spacing: 4;
            Button{
                id: start;
                text: "start";
                onClicked: colorMaker.start();
            }
            Button{
                id: stop;
                text: "stop";
                onClicked: colorMaker.stop();
            }

            Button{
                id: colorAlgorithm;
                text: "RandomRGB";
                onClicked: {
                    var algorithm = (colorMaker.algotithm() + 1) % 5;
                    qmlCTest.changeAlgorithm(colorAlgorithm, algorithm);
                    colorMaker.setAlgorithm(algorithm);
                }
            }

            Button{
                id: quit;
                text:"quit";
                onClicked: Qt.quit();
            }

        }
        Component.onCompleted: {
            colorMaker.color = Qt.rgba(0, 0.7, 0.47, 1);
            colorMaker.start();
        }
        Connections{
            target: colorMaker;
            onCurrentTime:{
                timeLabel.text = strTime;
                timeLabel.color = colorMaker.timeColor;
            }
        }
        Connections{
            target: colorMaker;
            onColorChange:{
                colorRec.color = color;
            }
        }
    }
    Rectangle{
        id: imageProcessorTest;
        anchors.top: qmlCTest.bottom;
        anchors.left: tabView.right;
        anchors.bottom: tabView.bottom;
        anchors.right: qmlCTest.right;
        border.color: "black";
        Image{
            id:imagePro;
            anchors.top: parent.top;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 60;
            fillMode: Image.PreserveAspectCrop;
            onStatusChanged: {
                if(imagePro.status === Image.Loading){
                    busy.running = true;
                }else{
                    busy.running = false;
                }
            }
        }
        ImageProcessor{
            id:imageProcessor;
            onFinished: {
                imagePro.source = "file:///" + newFile;
                busy.running = false;
            }
        }
        FileDialog{
            id: fileDialog;
            title: "Choose Image"

            nameFilters: ["Image files (*.jpg *.png *.gif)"];
            onAccepted: {
                console.log(fileDialog.fileUrl);
                imagePro.source = fileDialog.fileUrl;
            }
        }

        BusyIndicator{
            id:busy;
            running: false;
            anchors.centerIn: imagePro;
            z:2;
        }
        RowLayout{
            anchors.top:imagePro.bottom;
            anchors.topMargin: 5;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 5;
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            spacing: 4;
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "柔化";
                onClicked: {
                    busy.running = true;
                    console.log(fileDialog.fileUrl);
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Soften);
                }
            }
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "灰度";
                onClicked: {
                    busy.running = true;
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Gray);
                }
            }
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "浮雕";
                onClicked: {
                    busy.running = true;
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Emboss);
                }
            }
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "黑白";
                onClicked: {
                    busy.running = true;
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Binarize);
                }
            }
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "底片";
                onClicked: {
                    busy.running = true;
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Negative);
                }
            }
            MyControl.CtrButton{
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "锐化";
                onClicked: {
                    busy.running = true;
                    imageProcessor.process(fileDialog.fileUrl, ImageProcessor.Sharpen);
                }
            }
            MyControl.CtrButton{
                id: openImage;
                Layout.maximumWidth: 40;
                Layout.maximumHeight: 40;
                text: "打开";
                onClicked: {
                    fileDialog.visible = true;
                }
            }
        }
    }
    Rectangle{
            id:animationTest;
            width: 320;
            border.color: "black";
            color: "gray";
            anchors.left: canvasTest.right;
            anchors.top: canvasTest.top;
            anchors.bottom: canvasTest.bottom;
            TabBar{
                id:anibar;
                background: Rectangle{
                    border.color: "black";
                    opacity: 0.6
                }
                TabButton{
                    text: "1";
                    height: implicitHeight;
                    width: implicitWidth;
                }
                TabButton{
                    text: "2";
                }
                TabButton{
                    text: "3";
                }
                TabButton{
                    text: "4";
                }
                TabButton{
                    text: "5";
                }
                TabButton{
                    text: "6";
                }
            }
            StackLayout{
                anchors.top: anibar.bottom;
                anchors.left: parent.left;
                anchors.right: parent.right;
                anchors.bottom: parent.bottom;
                currentIndex: anibar.currentIndex;
                Rectangle{
                    border.color: "black";
                    color: "gray";
                    Rectangle{
                        id: properAnimation;
                        width: 50;
                        height: 150;
                        anchors.top: parent.top;
                        anchors.left: parent.left;
                        border.color: "black";
                        color: "pink";
                        PropertyAnimation{
                            id: animation;
                            target: properAnimation;
                            property: "width";
                            to: properAnimation.width == 150? 50 : 150;
                            duration: 650;
                            easing.type: Easing.InOutElastic;
                            easing.amplitude: 2.0;
                            easing.period: 1.5;
                        }


                        MouseArea{
                            anchors.fill: parent;
                            onClicked: animation.running = true;
                        }
                    }
                    Rectangle{
                        border.color: "black";
                        color: "red";
                        width: 50;
                        height: 50;
                        anchors.left: parent.left;
                        anchors.top: properAnimation.bottom;
                        PropertyAnimation on width{
                            to: properAnimation.width == 150? 50 : 150;
                            duration: 650;
                            easing.type: Easing.InOutElastic;
                            easing.amplitude: 2.0;
                            easing.period: 1.5;
                            running: tmouseArea.pressed;
                        }
                        MouseArea{
                            id: tmouseArea;
                            anchors.fill: parent;
                        }
                    }
                    Rectangle{
                        id: numberAnimation;
                        border.color: "black";
                        color: "blue";
                        width: 50;
                        height: 50;
                        x:150;
                        y:0;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                moveY.running = true;
                                recRotation.start();
                                recRadius.start();
                            }
                        }
                        NumberAnimation{
                            id: moveY;
                            target: numberAnimation;
                            property: "y";
                            to:150;
                            duration: 3000;
                            easing.type: Easing.OutInQuad;
                            onStarted:
                                ColorAnimation {
                                target: numberAnimation;
                                property: "color";
                                to: "red"
                                duration: 3000;
                            }
                        }
                        NumberAnimation{
                            id: recRotation;
                            target: numberAnimation;
                            property: "rotation";
                            to:1080;
                            duration: 3000;
                            easing.type: Easing.OutInQuad;

                        }
                        NumberAnimation on radius{
                            id: recRadius;
                            duration: 3000;
                            easing.type: Easing.OutInQuad;
                            to: 25;
                            running: false;
                        }

                    }
                    Rectangle{
                        id:rotaionAnimation;
                        width: 50;
                        height: 50;
                        color: "#187856";
                        border.color: "black";
                        x: 250;
                        y: 100;
                        transformOrigin: Item.TopLeft;
                        RotationAnimation{
                            loops: Animation.Infinite;
                            target: rotaionAnimation;
                            duration: 3000;
                            direction: RotationAnimation.Clockwise;
                            to: 360;
                            from: 0;
                            running: true;
                        }
                    }
                }
                Rectangle{
                    border.color: "black";
                    color: "gray";
                    Button{
                        anchors.bottom: parent.bottom;
                        text: "restart";
                        onClicked: {
                            pathAnimation.x = 0;
                            pathAnimation.y = 0;
                        }
                    }

                    Rectangle{
                        id: pathAnimation;
                        width: 50;
                        height: 50;
                        color: "pink";
                        MouseArea{
                            anchors.fill: parent;
                            id: pmouseArea;
                            onClicked: {
                                pathAnima.start();
                            }
                        }
                    }
                    PathAnimation{
                        id: pathAnima;
                        target: pathAnimation;
                        duration: 6000;
                        anchorPoint: "0,0";
                        orientationEntryDuration: 1000;
                        orientationExitDuration: 1000;
                        easing.type: Easing.InOutCubic;
                        orientation: PathAnimation.LeftFirst ;
                        path: Path{
                            startX: 80;
                            startY: 0;
                            PathArc{
                                x:240;
                                y:0;
                                useLargeArc: true;
                                radiusX: 80;
                                radiusY: 80;
                                direction: PathArc.Counterclockwise;
                            }
                        }
                    }

                    Canvas{
                        anchors.fill: parent;
                        contextType: "2d";
                        onPaint: {
                            context.lineWidth = 4;
                            context.strokeStyle = "blue";
                            context.beginPath();
                            context.arc(width/2, 0, width/4, 0, Math.PI, false);
                            context.stroke();
                        }
                    }

                }
                Rectangle{
                    border.color: "black";
                    color: "gray";
                    Rectangle{
                        id: smoothAnimation;
                        radius: 25;
                        border.color: "black";
                        width: 50;
                        height: 50;
                        color: "yellowgreen";
                    }
                    SmoothedAnimation{
                        id: smoothX;
                        target: smoothAnimation;
                        property: "x";
                        duration: 1000;
                        velocity: -1;
                    }
                    SmoothedAnimation{
                        id: smoothY;
                        target: smoothAnimation;
                        property: "y";
                        velocity: 100;
                    }

                    Rectangle{
                        id: springAnimation;
                        width: 50;
                        height: 50;
                        radius: 25;
                        border.color: "black";
                        color: "pink";
                        x:0;
                        y:51;
                    }
                    SpringAnimation{
                        id: springX;
                        target: springAnimation;
                        property: "x";
                        spring: 3;
                        damping: 0.06;
                        epsilon: 0.25;
                    }
                    SpringAnimation{
                        id: springY;
                        target: springAnimation;
                        property: "y";
                        spring: 3;
                        damping: 0.06;
                        epsilon: 0.25;
                    }

                    MouseArea{
                        anchors.fill: parent;
                        onClicked: {
                            smoothX.stop();
                            smoothY.stop();
                            smoothX.from = smoothAnimation.x;
                            smoothX.to = mouse.x-25;
                            smoothX.start();
                            smoothY.from = smoothAnimation.y;
                            smoothY.to = mouse.y-25;
                            smoothY.start();
                            springX.stop();
                            springY.stop();
                            springX.from = smoothAnimation.x;
                            springX.to = mouse.x-25;
                            springX.start();
                            springY.from = smoothAnimation.y;
                            springY.to = mouse.y-25;
                            springY.start();
                        }
                    }
                }
                Rectangle{
                    border.color: "black";
                    color: "gray";
                    Rectangle{
                        id: parallelAnimation;
                        anchors.verticalCenter: parent.verticalCenter;
                        border.color: "black";
                        color:"blue";
                        width: 50;
                        height: 50;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked:if(pAnima.paused){
                                pAnima.resume();
                            }else if(pAnima.running){
                                          pAnima.pause();
                                      }else{
                                          pAnima.start();
                                      }
                        }

                    }

                    ParallelAnimation{
                        id:pAnima;
                        loops: Animation.Infinite;
                        NumberAnimation{
                            target: parallelAnimation;
                            property: "x";
                            to: 270;
                            duration: 3000;
                        }
                        NumberAnimation{
                            target: parallelAnimation;
                            property: "rotation";
                            to: 360;
                            duration: 3000;
                        }
                        NumberAnimation{
                            target: parallelAnimation;
                            property: "radius";
                            to: 25;
                            duration: 3000;
                        }
                    }
                    Rectangle{
                        id: sequentialAnimation;
                        border.color: "black";
                        color:"blue";
                        width: 50;
                        height: 50;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked:if(sAnima.paused){
                                sAnima.resume();
                            }else if(sAnima.running){
                                          sAnima.pause();
                                      }else{
                                          sAnima.start();
                                      }
                        }
                    }

                    SequentialAnimation{
                        id:sAnima;
                        loops: Animation.Infinite;
                        NumberAnimation{
                            target: sequentialAnimation;
                            property: "x";
                            to: 270;
                            duration: 3000;
                        }
                        NumberAnimation{
                            target: sequentialAnimation;
                            property: "rotation";
                            to: 360;
                            duration: 3000;
                        }
                        NumberAnimation{
                            target: sequentialAnimation;
                            property: "radius";
                            to: 25;
                            duration: 3000;
                        }
                    }
                }
                Rectangle{
                    border.color: "black";
                    color: "white";
                    Text{
                        id: linkText;
                        text: "I'm web link!";
                        anchors.horizontalCenter: parent.horizontalCenter;
                        anchors.top: parent.top;
                        anchors.topMargin: 4;
                        font.pixelSize: 18;
                        property bool hadClicked: false;
                        MouseArea{
                            id: statMouse;
                            anchors.fill: parent;
                            hoverEnabled: true;
                            onEntered: {
                                linkText.state = linkText.hadClicked == true?
                                            "clickedHover":"hover";
                            }
                            onExited: {
                                linkText.state = linkText.hadClicked == true?
                                            "clicked":"initial";
                            }
                            onClicked: {
                                if(linkText.hadClicked == false){
                                    linkText.hadClicked = true;
                                }
                                linkText.state = "clicked";
                            }
                        }
                        states: [
                            State{
                                name: "initial";
                                changes: [
                                    PropertyChanges {
                                        target: linkText;
                                        color: "blue";
                                    }
                                ]
                            },
                            State{
                                name: "hover";
                                PropertyChanges{
                                    target: linkText;
                                    color: "#87CEFA";

                                    font.italic: true;
                                    font.pixelSize: 20;
                                    font.underline: true;

                                }
                            },
                            State {
                                name: "clicked"
                                PropertyChanges {
                                    target: linkText;
                                    color: "#8B4513";
                                    font.pixelSize: 25;
                                    rotation: 360;
//                                    anchors.topMargin: 20;
                                }
//                                AnchorChanges{
//                                    anchors.top: parent.top;
//                                }
                            },
                            State {
                                name: "clickedHover";
                                PropertyChanges {
                                    target: linkText;
                                    color: "#D2691E";
                                    font.italic: true;
                                    font.pixelSize: 29;
                                    font.underline: true;
                                }
                            }
                        ]
                        state: "initial";
                        transitions: [
                            Transition {
                                from: "initial";
                                to: "hover";
                                reversible: true;
                                ParallelAnimation{
                                    NumberAnimation{
                                        property: "font.pixelSize";
                                        duration: 800;
                                    }
                                    ColorAnimation {
                                        duration: 800;
                                    }
                                }
                            },
                            Transition {
                                from: "hover"
                                to: "clicked"
                                ParallelAnimation{
                                    NumberAnimation{
                                        properties: "font.pixelSize";
                                        duration: 800;
                                    }
                                    ColorAnimation {
                                        duration: 800;
                                    }
                                    RotationAnimation{
                                        property: "rotation";
                                        direction: RotationAnimation.Clockwise;
                                        duration: 800;
                                    }
                                }
                            },
                            Transition {
                                from: "clicked"
                                to: "clickedHover"
                                reversible: true;
                                SequentialAnimation{
                                    NumberAnimation{
                                        property: "font.pixelSize";
                                        duration: 800;
                                    }
                                    ColorAnimation {
                                        duration: 800;
                                    }
                                }
                            }
                        ]
                    }
                }
                Rectangle{
                    border.color: "black";
                    Button{
                        text: "bubbleShot";
                        anchors.centerIn: parent;
                        BubbleShot{
                            id: bubbleshot;
                            color: "#e0e0e0";
                            Component.onCompleted: {
                                bubbleshot.fireSignal.connect(fire);
                            }

                            Row{
                                id: bubbles;
                                anchors.top: parent.top;
                                anchors.horizontalCenter: parent.horizontalCenter;
                                spacing: 2;
                                property int diedCount: 0;
                                function allDie(){
                                    return diedCount === children.length;
                                }
                                function reset(){
                                    diedCount = 0;
                                    var i = 0;
                                    var bubble;
                                    for(; i<bubbles.children.length; i++){
                                        bubble = bubbles.children[i];
                                        bubble.died = false;
                                        bubble.cSource = "images/xzq.jpg";
                                        bubble.children[0].requestPaint();
                                        bubble.opacity = 1.0;
                                    }
                                }
                                Component.onCompleted: {
                                    var i = 0;
                                    var qmlStringBegin = "
                                    import QtQuick 2.2;\
                                    Rectangle{\
                                        width:50;\
                                        height:50;\
                                        opacity:1.0;\
                                        property var died: false;\
                                        property var cSource : \"images/xzq.jpg\";\
                                        color:bubbleshot.color;\
                                        Canvas{\
                                            anchors.fill: parent;\
                                            contextType: \"2d\";\
                                            onPaint: {\
                                                context.strokeStyle = \"black\";\
                                                context.lineWidth = 1;\
                                                context.beginPath();\
                                                context.arc(width/2, height/2, 25, 0, Math.PI*2);\
                                                context.clip();\
                                                context.drawImage(cSource, 0, 0, width, height);\
                                                context.stroke();\
                                            }\
                                            Component.onCompleted: {\
                                                loadImage(cSource);\
                                            }\
                                            onImageLoaded: requestPaint();\
                                        }\
                                    }"
                                    for(; i<8; i++){
                                        bubbles.children[i] = Qt.createQmlObject(qmlStringBegin, bubbles, "");
                                    }
                                }
                            }
                            Text{
                                id: scoreInfo;
                                anchors.horizontalCenter: parent.horizontalCenter;
                                anchors.top: bubbles.bottom;
                                anchors.topMargin: 4;
                                font.pixelSize: 26;
                                font.bold: true;
                                color: "blue";
                            }
                            Rectangle{
                                id: turret;
                                width: 80;
                                height: 240;
                                anchors.horizontalCenter: parent.horizontalCenter;
                                anchors.bottom: parent.bottom;
                                anchors.bottomMargin: -120;
                                color:bubbleshot.color;
                                z:2;
                                rotation: bubbleshot.tuttenAngle;
                                Canvas{
                                    id: turrentCanvas;
                                    anchors.fill: parent;
                                    contextType: "2d";
                                    onPaint: {
                                        context.lineWidth = 2;
                                        context.strokeStyle = "black";
                                        var gradient = context.createLinearGradient(0, 0, 80, 120);
                                        gradient.addColorStop(0, "white");
                                        gradient.addColorStop(1, "darkslateblue");
                                        context.fillStyle = gradient;
                                        context.save();
                                        context.beginPath();
                                        context.arc(width/2, height-120, width/2-2, 0, Math.PI*2, true);
                                        context.moveTo(width/3, height-30);
                                        context.lineTo(width/2, 0);
                                        context.lineTo(width*2/3, height-30);
                                        context.stroke();
                                        context.fill();
                                    }
                                }
                                Behavior on rotation {
                                    NumberAnimation {
                                        duration: 100;
                                    }
                                }
                            }
                            Rectangle{
                                id: bullet;
                                x: turret.x + turret.width/2 - width/2;
                                y: turret.y + turret.height/2;
                                width: 25;
                                height: 25;
                                z:0;
                                color: "white";
                                radius: 20;
                                visible: false;
                            }

                            NumberAnimation{
                                id: aboutDie;
                                properties: "opacity";
                                duration: 400;
                                from:1.0;
                                to:0;
                                onStopped: {
                                    showDie.start();
                                }
                            }
                            NumberAnimation{
                                id: showDie;
                                duration: 400;
                                properties: "opacity";
                                from:0;
                                to:0.4;
                                property var diedImage;
                                onStarted: {
                                    target.cSource = diedImage;
                                    target.children[0].requestPaint();
                                }
                                onStopped: {
                                    bubbles.diedCount++;
                                    if(bubbles.allDie() === true){
                                        passed.showPass(true);
                                        deadline.stop();
                                        bubbleshot.showScore();
                                    }
                                }
                            }
                            ParallelAnimation{
                                id: animationBullet;
                                property int fire: 0;
                                property int dieBubble: -1;
                                function caculateDiedBubble(){
                                    var bubble;
                                    var i = 0;
                                    for(dieBubble = -1; i<bubbles.children.length; i++){
                                        bubble = bubbles.children[i];
                                        if(bubbleshot.bulletTrackX > bubbles.x+bubble.x &&
                                                bubbleshot.bulletTrackX < bubbles.x+bubble.x+bubble.width){
                                            if(bubble.died === false){
                                                dieBubble = i;
                                                break;
                                            }
                                        }
                                    }
                                }
                                 NumberAnimation{
                                     id:animationBulletX;
                                     target: bullet;
                                     property: "x";
                                     duration: 1200;
                                     easing.type: Easing.OutCubic;
                                 }
                                 NumberAnimation{
                                     id:animationBulletY;
                                     target: bullet;
                                     property: "y";
                                     duration: 1200;
                                     easing.type: Easing.OutCubic;
                                 }
                                 onStopped: {
                                     if(fire === 1){
                                         if(dieBubble >= 0){
                                             var bubble = bubbles.children[dieBubble];
                                             bubble.died = true;
                                             showDie.diedImage = "images/0_xzq.jpg";
                                             aboutDie.target = bubble;
                                             showDie.target = bubble;
                                             aboutDie.start();
                                         }
                                     }
                                     fire = 0;
                                     bullet.visible = false;
                                     bullet.x = turret.x + turret.width/2;
                                     bullet.y = turret.y + turret.height/2;

                                 }
                            }
                            function fire(){
                                if(animationBullet.fire === 0){
                                    animationBullet.fire = 1;
                                    bullet.visible = true;
                                    if(bubbleshot.bulletTrackX >=0 && bubbleshot.bulletTrackX <= bubbleshot.width){
                                        animationBulletX.to = bubbleshot.bulletTrackX;
                                        animationBulletY.to = bubbles.height + bullet.width/2;
                                    }else if(bubbleshot.bulletTrackX < 0){
                                        animationBulletX.to = 0;
                                        animationBulletY.to = bubbleshot.height-(Math.tan((90+bubbleshot.tuttenAngle)*Math.PI/180)*(bubbleshot.width/2));
//                                        console.log("to = "+animationBulletY.to);
                                    }else if(bubbleshot.bulletTrackX > bubbleshot.width){
                                        animationBulletX.to = bubbleshot.width;
                                        animationBulletY.to = bubbleshot.height-(Math.tan((90-bubbleshot.tuttenAngle)*Math.PI/180)*(bubbleshot.width/2));
                                    }
                                    animationBullet.caculateDiedBubble();
                                    animationBullet.start();
                                }
                            }
//                            function resetBullet(){

//                            }
                            Text {
                                id: leftSeconds;
                                anchors.centerIn: parent;
                                color: "red";
                                font.pixelSize: 20;
                            }
                            property var startDate;
                            property bool requestReset: false;
                            readonly property int maxGameTime: 70000;
                            Button{
                               id:resetGame;
                               text: "Reset";
                               anchors.left: parent.left;
                               anchors.leftMargin: 4;
                               anchors.bottom: parent.bottom;
                               anchors.bottomMargin: 4;
                               onClicked: {
                                   bubbleshot.requestReset = true;
                                   bubbles.reset();
                                   deadline.stop();
                                   failed.showFailed(false);
                                   passed.showPass(false);
                                   leftSeconds.text = "";
                                   scoreInfo.text = "";
                                   if(animationBullet.running === true){
                                       animationBullet.stop();
                                       animationBullet.fire = 0;
                                   }
                                   playGame.enabled = true;
                               }
                            }

                            Button{
                                id: playGame;
                                text: "Play";
                                anchors.left: parent.left;
                                anchors.leftMargin: 4;
                                anchors.bottom: resetGame.top;
                                anchors.bottomMargin: 4;
                                onClicked: {
                                    bubbleshot.startDate = new Date;
                                    deadline.restart();
                                    playGame.enabled = false;
                                    bubbleshot.requestReset = false;
                                    bubbleshot.enable(true);
                                }
                            }

                            Timer{
                                id: deadline;
                                interval: 1000;
                                repeat: true;
                                onTriggered: {
                                    var curDate = new Date;
                                    var milliSecounds = bubbleshot.maxGameTime - (curDate.getTime() - bubbleshot.startDate.getTime());
                                    if(milliSecounds <= 0){
                                        failed.showFailed(true);
                                        bubbleshot.enable(false);
                                        deadline.stop();
                                    }else{
                                        var secounds = Math.round(milliSecounds/1000);
                                        if(secounds == 0)
                                            secounds =  1;
                                        leftSeconds.text = "Left time:" + secounds;
                                    }
                                }
                            }
                            Text{
                                id: passed;
                                visible: false;
                                width: 200;
                                height: 50;
                                text: "PASSED!";
                                font.pixelSize: 50;
                                font.bold: true;
                                x: bubbleshot.width/2 - 100;
                                z:3;
                                SpringAnimation{
                                    id: passedSpringY;
                                    target: passed;
                                    properties: "y";
                                    spring: 3;
                                    damping: 0.1;
                                    epsilon: 0.25;
                                }
                                function showPass(bShow){
                                    visible = bShow;
                                    if(bShow === true){
                                        passedSpringY.from = y;
                                        passedSpringY.to = bubbleshot.height/2 - height/2;
                                        passedSpringY.start();
                                    }else{
                                        y = 0;
                                    }
                                }
                            }
                            Text{
                                id:failed;
                                visible: false;
                                width: 200;
                                height: 50;
                                text: "FAILED!";
                                font.pixelSize: 50;
                                font.bold: true;
                                z:3;
                                states: [
                                    State {
                                        name: "Show";
                                        AnchorChanges {
                                            target: failed;
                                            anchors.horizontalCenter: parent.horizontalCenter;
                                            anchors.verticalCenter: parent.verticalCenter;
                                        }
                                    },
                                    State {
                                        name: "Hide";
                                        AnchorChanges {
                                            target: failed;
                                            anchors.left: bubbleshot.left;
                                            anchors.top: bubbleshot.top;
                                        }
                                    }
                                ]
                                state: "Hide";
                                transitions: Transition {
                                    AnchorAnimation{
                                        duration: 1000;
                                        easing.type: Easing.OutInCubic;
                                    }
                                }
                                function showFailed(bShow){
                                    visible = bShow;
                                    state = bShow === true? "Show":"Hide";
                                }
                            }
                            function showScore(){
                                var curDate = new Date;
                                var secounds = Math.round((curDate.getTime() - bubbleshot.startDate.getTime())/1000);
                                if(secounds <= 27){
                                    scoreInfo.text = secounds + "S! Excellent!";
                                }else if(secounds <= 32){
                                    scoreInfo.text = secounds + "S! Good!";
                                }else if(secounds <= 42){
                                    scoreInfo.text = secounds + "S! Yep pass!";
                                }else{
                                    scoreInfo.text = secounds + "S! Try again!";
                                }
                            }
                        }
                            onClicked:{
                            bubbleshot.show();
                        }
                    }
                }
            }
        }
    Rectangle{
        id: modelViewTest;
        anchors.top: animationTest.bottom;
        anchors.left: animationTest.left;
        anchors.right: animationTest.right;
        anchors.bottom: qmlCTest.bottom;
        border.color: "black";
        color: "gray";

        TabBar{
            id: modelBar;
            background: Rectangle{
                border.color: "black";
                opacity: 0.6
            }
            TabButton{
                text: "1";
            }
            TabButton{
                text: "2";
            }
            TabButton{
                text: "3";
            }
            TabButton{
                text: "4";
            }
            TabButton{
                text: "5";
            }
            TabButton{
                text: "6";
            }
        }
        StackLayout{
            anchors.top: modelBar.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.bottom: parent.bottom;
            currentIndex: modelBar.currentIndex;
            opacity: 1;
            Rectangle{
                id: listViewRec;
                clip: true;
                Component{
                    id:phoneModel;
                    ListModel{
                        ListElement{
                            name: "iphone XS";
                            cost: 1000;
                            manufacturer: "Apple";
                        }
                        ListElement{
                            name: "iphone 11";
                            cost: 5000;
                            manufacturer: "Apple";
                        }
                        ListElement{
                            name: "iphone 11pro";
                            cost: 7000;
                            manufacturer: "Apple";
                        }
                        ListElement{
                            name: "iphone 12pro";
                            cost: 9000;
                            manufacturer: "Apple";
                        }
                        ListElement{
                            name: "MI12";
                            cost: 5000;
                            manufacturer: "xioami";
                        }
                        ListElement{
                            name: "MI10";
                            cost: 5000;
                            manufacturer: "xioami";
                        }
                        ListElement{
                            name: "Mate40";
                            cost: 7590;
                            manufacturer: "HuaWei";
                        }
                        ListElement{
                            name: "S5";
                            cost: 4699;
                            manufacturer: "SamSung";
                        }
                    }

                }
                Component{
                    id: phoneHeader;
                    Item{
                        width: parent.width;
                        height: 30;
                        RowLayout{
                            anchors.left: parent.left;
                            anchors.verticalCenter: parent.verticalCenter;
                            spacing: 8;
                            Text{
                                text: "Name";
                                font.bold: true;
                                font.pixelSize: 20;
                                Layout.preferredWidth: 120;
                            }
                            Text{
                                text: "Cost";
                                font.bold: true;
                                font.pixelSize: 20;
                                Layout.preferredWidth: 80;
                            }
                            Text{
                                text: "Manufacturer";
                                font.bold: true;
                                font.pixelSize: 20;
                                Layout.fillWidth: true;
                            }
                        }
                    }
                }
                Component{
                    id: footerView;
                    Item {
                        id:footerRootItem;
                        width: parent.width;
                        height: 30;
                        signal clean();
                        signal add();
                        signal insert();
                        property alias text: txt.text;
                        Row{
                            width: parent.width;
                        Text{
                            id: txt;
//                            anchors.top: parent.top;
//                            anchors.left: parent.left;
//                            anchors.bottom: parent.bottom;
                            font.italic: true;
                            color: "blue";
                            verticalAlignment: Text.AlignVCenter;
                        }
                        Button{
                            id: clearAll;
//                            anchors.right: parent.right;
//                            anchors.verticalCenter: parent.verticalCenter;
                            text:"Clear";
//                            width: availableWidth;
//                            width: implicitWidth;
                            width:implicitContentWidth
                            onClicked:footerRootItem.clean();
                        }
                        Button{
                            id: addOne;
//                            anchors.right: clearAll.left;
//                            anchors.rightMargin: 4;
//                            anchors.verticalCenter: parent.verticalCenter;
                            text: "Add";
//                            width: availableWidth;
//                            width: implicitWidth;
                            onClicked: footerRootItem.add();
                        }
                        Button{
                            id: insertOne;
//                            width: availableWidth;
//                            width: implicitWidth;
                            text: "Insert";
                            onClicked: footerRootItem.insert();
                        }
                        }
                    }
                }
                Component{
                    id:phoneDelegate;
                    Item{
                        id: wrapper;
                        width: parent.width;
                        height: 30;
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: wrapper.ListView.view.currentIndex = index;
                            onDoubleClicked: {
                                wrapper.ListView.view.model.remove(index);
                            }
                        }
                        RowLayout{
                            anchors.left: parent.left;
                            anchors.verticalCenter: parent.verticalCenter;
                            spacing: 8;
                            Text {
                                id: coll;
                                text: name;
                                color: wrapper.ListView.isCurrentItem? "red":"black";
                                font.pixelSize: wrapper.ListView.isCurrentItem? 22:18;
                                Layout.preferredWidth: 120;
                            }
                            Text {
                                text: cost;
                                color:wrapper.ListView.isCurrentItem? "red":"black";
                                font.pixelSize: wrapper.ListView.isCurrentItem? 22:18;
                                Layout.preferredWidth: 80;
                            }
                            Text {
                                text: manufacturer;
                                color:wrapper.ListView.isCurrentItem? "red":"black";
                                font.pixelSize: wrapper.ListView.isCurrentItem? 22:18;
                                Layout.fillWidth: true;
                            }

                        }
                    }
                }
                Component{
                    id: sectionHeader;
                    Rectangle{
                        width: parent.width;
                        height: xx.height;
                        color: "lightsteelblue";
                        Text{
                            id:xx;
                            text: section;
                            font.bold: true;
                            font.pixelSize: 20;
                        }
                    }
                }
                ListView{
                    id: listView;
                    anchors.fill: parent;
                    model: phoneModel.createObject(listView);
                    delegate: phoneDelegate;
                    header: phoneHeader;
                    footer: footerView;
                    headerPositioning:ListView.OverlayHeader;
                    function addone(){
                        model.append({"name" : "MX3",
                                   "cost" : 1799,
                                   "manufacturer" : "MeiZu"
                               }
                                   );
                    }

                    function insertOne(){
                        model.insert(
                                    currentIndex + 1, {"name" : "HTC One E8",
                                         "cost" : 2999,
                                         "manufacturer" : "HTC"
                                     }
                                     );
                    }
                    section.property: "manufacturer";
                    section.criteria: ViewSection.FullString;
                    section.delegate: sectionHeader;

                    Component.onCompleted: {
                        listView.footerItem.clean.connect(listView.model.clear);
                        listView.footerItem.add.connect(listView.addone);
                        listView.footerItem.insert.connect(listView.insertOne);
                    }
                    add: Transition {
                        ParallelAnimation{
                            NumberAnimation{
                                property: "opacity";
                                from: 0;
                                to: 1.0;
                                duration: 1000;
                            }
                            NumberAnimation{
                                property:"y";
                                from: 0;
                                duration: 1000;
                            }
                        }
                    }
                    populate: Transition {
                        NumberAnimation {
                            properties: "x,y";
                            duration: 1000;
                        }
                    }
                    displaced: Transition {
                        NumberAnimation {
                            properties: "x,y";
                            duration: 1000;
                        }
                    }
                    remove: Transition{
                        ParallelAnimation {
                            NumberAnimation {
                                property: "opacity";
                                to: 0;
                                duration: 1000 ;
                            }
                            NumberAnimation {
                                properties: "x,y";
                                to: 100;
                                duration: 1000;
                            }
                        }
                    }

                    highlight: Rectangle {
                        color: "lightsteelblue"; radius: 5;
                        y: listView.currentItem.y
                        Behavior on y {
                            SpringAnimation {
                                spring: 3
                                damping: 0.2
                            }
                        }
                    }
                    onCurrentIndexChanged: {
                        if(listView.currentIndex >= 0){
                            var data = listView.model.get(listView.currentIndex);
                            listView.footerItem.text = data.name + "," + data.cost + "," + data.manufacturer;
                        }else{
                            listView.footerItem.text = " ";
                        }
                    }
                }
            }
            Rectangle{
                id: tableViewRec;
                QmlTableView{
                    anchors.fill: parent;
                }
            }
            Rectangle{
                id: pathViewRec;
                Component{
                    id: pathViewDelegate;
                    Item{
                        id: pathVWapper;
                        z: PathView.zOrder;
                        opacity: PathView.itemAlpha;
                        scale:PathView.itemScale;
                        Rectangle{
                            width: 100;
                            height: 60;
                            color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                            border.width: 2;
                            border.color: pathVWapper.PathView.isCurrentItem? "red":"lightgray";
                            Text{
                                id: ptxt;
                                anchors.centerIn: parent;
                                font.pixelSize: 28;
                                text: index;
                                color: Qt.lighter(parent.color, 2);
                            }
                        }
                    }
                }
                PathView{
                    id: pathView;
                    anchors.fill: parent;
                    interactive: true;
                    pathItemCount: 12;
                    preferredHighlightBegin: 0.5;
                    preferredHighlightEnd: 0.5;
                    highlightRangeMode: PathView.StrictlyEnforceRange;
                    delegate: pathViewDelegate;
                    model: 15;
                    Button{
                        id:prev;
                        text:"<<";
                        enabled: true;
                        onClicked: {
                            pathView.decrementCurrentIndex();
                        }
                    }
                    Button{
                        text:">>";
                        anchors.left: prev.right;
                        onClicked: {
                            pathView.incrementCurrentIndex();
                        }
                    }
                    path: Path{
                        startX: 0;
                        startY: 100;
                        PathAttribute{
                            name: "zOrder";
                            value: 0;
                        }
                        PathAttribute{
                            name:"itemAlpha";
                            value: 0.1;
                        }
                        PathAttribute{
                            name: "itemScale";
                            value: 0.6;
                        }

                        PathLine{
                            x: pathViewRec.width/2-50;
                            y: 100;
                        }
                        PathPercent{
                            value: 0.28;
                        }
                        PathAttribute{
                            name: "zOrder";
                            value: 10;
                        }
                        PathAttribute{
                            name:"itemAlpha";
                            value: 0.8;
                        }
                        PathAttribute{
                            name: "itemScale";
                            value: 1.2;
                        }

                        PathLine{
                            relativeX: pathViewRec.width/2-60;
                            relativeY: 0;
                        }
                        PathAttribute{
                            name: "zOrder";
                            value: 0;
                        }
                        PathAttribute{
                            name:"itemAlpha";
                            value: 0.1;
                        }
                        PathAttribute{
                            name: "itemScale";
                            value: 0.6;
                        }
                    }
                }
            }
            Rectangle{
                id: pictureBrowser;
                MyControl.CtrButton{
                    width: 100;
                    height: 100;
                    anchors.centerIn: parent;
                    text: "creatWindow";
                    onClicked: {
                        var component = Qt.createComponent("PictureWindow.qml");
                        var win = component.createObject();
                        win.closing.connect(function(){win.destroy()});
                        win.show();
                    }
                }
            }
            Rectangle{
                id: repeaterRec;
                RowLayout{
                    anchors.fill: parent;
                    spacing: 4;
                    Repeater{
                        model: 8;//可以设置为数字,字符列表,对象列表,ListModel使用
                        Rectangle{
                            width: 50;
                            height: 50;
                            color:"steelblue";
                        }
                    }
                }
            }
            Rectangle{
                id: dropDownRefresh;
                Component{
                    id: dropDownRefreshDelegate
                    Text{
                        id: dDwrapper;
                        width: parent.width;
                        height: 32;
                        font.pixelSize: 15;
                        verticalAlignment: Text.AlignVCenter;
                        horizontalAlignment: Text.AlignHCenter;
                        text: content;//直接饮用model的data内容
                        color: ListView.view.currentIndex === index? "red":"blue";
                        MouseArea{
                            anchors.fill: parent;
                            onClicked: {
                                if(dDwrapper.ListView.view.currentIndex !== index){
                                    dDwrapper.ListView.view.currentIndex = index;
                                }
                            }
                        }
                    }
                }
                ListView{
                    id: dynamicList;
                    z:1;
                    anchors.fill: parent;
                    anchors.margins: 10;
                    delegate: dropDownRefreshDelegate;
                    model: dynamicModel;

                    highlight: Rectangle{
                        color: "steelblue";
                    }
                    property real contentYOnFlickStarted: 0;
                    onFlickStarted: {
                        contentYOnFlickStarted = contentY;
                    }
                    onFlickEnded: {
                        dynamicModel.loadMore(contentY < contentYOnFlickStarted);
                    }
                }
            }
        }
    }
}
