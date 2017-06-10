import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.2

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1024
    height: 600
    title: qsTr("QuizT")
    visibility: "FullScreen" // Uses fulSlscreen as default. Works on both, PC and mobile.

    //The background color
    Rectangle {
        id: background
        color: "#FFFFFF"
        visible: true
        border.width: 0
        anchors.fill: parent
    }

    //Background image animation
    property int imageInUsing: 0
    Image {
        id: backgroundImage
        x: mainWindow.width - (mainWindow.width / 2); y: mainWindow.height - (mainWindow.height / 2)
        width: mainWindow.width + 50; height: mainWindow.height + 50
        source: "./images/images/Backgrounds/0.jpg"

        SequentialAnimation
        {
            running: true
            loops: Animation.Infinite

               ParallelAnimation {
                    NumberAnimation {
                        target: backgroundImage
                        properties: "x"
                        to: -50
                        duration: 3000
                    }

                    NumberAnimation {
                        target: backgroundImage
                        properties: "y"
                        to: -50
                        duration: 3000
                    }
                }

               PauseAnimation { duration: 2000 }

                NumberAnimation {
                    target: backgroundImage
                    properties: "opacity"
                    to: 0
                    duration: 2000
                }

                ScriptAction {
                    script: {
                        imageInUsing++;
                        if(imageInUsing >= 15)
                            imageInUsing = 0;
                        backgroundImage.source = "./images/images/Backgrounds/" + imageInUsing.toString() + ".jpg";

                        backgroundImage.x = mainWindow.width - (mainWindow.width / 2);
                        backgroundImage.y = mainWindow.height - (mainWindow.height / 2);
                    }
                }

                NumberAnimation {
                    target: backgroundImage
                    properties: "opacity"
                    from: 0
                    to: 1
                    duration: 2000
                }
        }
    }

    //Each question page is called as an item on this StackView
    StackView {
        id: pageView
        anchors.fill: parent
        anchors.margins: 20
        initialItem: newQuestion
    }

    //The question Component
    property Component newQuestion : QuestionPage {}
}
