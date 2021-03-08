import QtQuick 2.12
import QtQuick.Controls 2.12
RadioButton{
    id:control;
    text:"RadioButton"
    indicator:Rectangle{
        implicitWidth:32;
        implicitHeight: 26;
        x: control.rightPadding;
        y:parent.height/2 - height/2;
        radius:13;
        border.color: control.down? "pink" : "black";
        Rectangle{
            width: 14;
            height: 14;
            x:6;
            y:6;
            radius: 14;
            color: control.down?"white" : "black";
            visible: control.checked;
        }

    }
    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#17a81a" : "#black"
        verticalAlignment: Text.AlignVCenter
        leftPadding: control.indicator.width + control.spacing
    }
}

