import QtQuick 2.7

//Background image animation

Image {
    id: bgImage
    x: mainWindow.width - (mainWindow.width / 2); y: mainWindow.height - (mainWindow.height / 2)
    width: mainWindow.width + 50; height: mainWindow.height + 50
    source: backgroundImages.nextImage;

    property int imageInUsing: 0

    SequentialAnimation
    {
        running: true
        loops: Animation.Infinite

           ParallelAnimation {
                NumberAnimation {
                    target: bgImage
                    properties: "x"
                    to: -50
                    duration: 3000
                }

                NumberAnimation {
                    target: bgImage
                    properties: "y"
                    to: -50
                    duration: 3000
                }
            }

           PauseAnimation { duration: 2000 }

            NumberAnimation {
                target: bgImage
                properties: "opacity"
                to: 0
                duration: 2000
            }

            ScriptAction {
                script: {
                    imageInUsing++;
                    if(imageInUsing >= 15)
                        imageInUsing = 0;
                    bgImage.source = backgroundImages.nextImage;

                    bgImage.x = mainWindow.width - (mainWindow.width / 2);
                    bgImage.y = mainWindow.height - (mainWindow.height / 2);
                }
            }

            NumberAnimation {
                target: bgImage
                properties: "opacity"
                from: 0
                to: 1
                duration: 2000
            }
    }
}
