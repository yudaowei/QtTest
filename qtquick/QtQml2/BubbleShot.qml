import QtQuick 2.0
import QtQuick.Window 2.2
Window {
    id: bubbleShot;
    width: 580;
    height: 650;
    title: "Bubble";
    property double tuttenAngle:0;
    property double bulletTrackX: 0;
    signal fireSignal();
    Component.onDestruction: {
        console.log("destruction Bubble")
    }
    function enable(s){
        mouseA.enabled = s;
    }

    MouseArea{
        id: mouseA;
        enabled: false;
        anchors.fill: parent;
        hoverEnabled: true;
        onPositionChanged: {
            if(mouseX > width/2){
                tuttenAngle = (90 - Math.atan((height-mouseY)/(mouseX-width/2))/Math.PI*180).toFixed(2);
            }else if(mouseX < width/2){
                tuttenAngle =(Math.atan((height - mouseY)/(width/2 - mouseX))/Math.PI*180 - 90).toFixed(2);
            }else{
                tuttenAngle = 0;
            }
        }
        onClicked: {
            var radian;
            if(mouseX > width/2){
                radian = tuttenAngle*Math.PI/180;
                bulletTrackX = Math.tan(radian)*(height-50-12.5) + width/2;
            }else if(mouseX < width/2){
                radian = (-tuttenAngle)*Math.PI/180;
                bulletTrackX = width/2 - Math.tan(radian)*(height-50-12.5);
            }else{
                bulletTrackX = width/2;
            }
            bubbleShot.fireSignal();
        }
    }
}
