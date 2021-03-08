import QtQuick 2.0
import QtQuick.Controls 2.5
Button {
    id: control;
    width: 60;
    height: 60;
    font.bold: true;
    font.pixelSize: 15;


    contentItem: Text {
        text: control.text;
        font: control.font;

        color: control.down? "black" : "cornflowerblue";
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
    }
    background: Rectangle{
        opacity: 0.6;
        implicitWidth: width;
        implicitHeight: height;
        border.color: control.down? "pink" : "black";
        color: control.down? "black" : "pink";
        border.width: 1;
        radius: control.width/2;
    }
}
