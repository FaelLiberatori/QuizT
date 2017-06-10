import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Button {
    id: answerButton

    /* Note: Qt/QML only can use one image object to one button at a time,
            but Qt will NOT duplicat the file in ram if you use the same "source" file,
            then our image file is cached just one time. */

    // It has other buttons in "images" folder, you can change if you want,
    // just remenber to put your button name into the "qml.qrc" file.
    background: Image { source: "./images/button1.png" }
    opacity: 0.5
    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    Layout.fillHeight: true
    Layout.fillWidth: true
    onClicked: z == 0 ? wrongButtonAnim.start() : rightButtonAnim.start() // I'm using the z position to wrong/right (like false/true, 0/1)

    //Animations
    SequentialAnimation {
        id: wrongButtonAnim
        PropertyAnimation { target: colorId1; properties: "color"; to: "#73ff0000"; duration: 700 }
        PropertyAnimation { target: colorId1; properties: "color"; to: "#73FFFFFF"; duration: 700 }
    }

    SequentialAnimation {
        id: rightButtonAnim
        PropertyAnimation { target: colorId1; properties: "color"; to: "#7366ff33"; duration: 700 }
        PropertyAnimation { target: colorId1; properties: "color"; to: "#73FFFFFF"; duration: 1200 }
        onRunningChanged: !running ? pageView.push(newQuestion) : null
    }

    // Overlay the button color
    // It's only as children to not use one unecessary cell space or wharever you are using as layout.
    ColorOverlay {
        id: colorId1
        color: "#73FFFFFF"
        anchors.fill: answerButton
        source: answerButton
    }

    Text {
        id: answerButtonTxt
        x: -3
        y: 5
        z: 0
        font.family: "Tahoma"
        scale: 1
        anchors.bottomMargin: 30
        anchors.fill: parent
        elide: Text.ElideNone
        horizontalAlignment: Text.AlignHCenter
        anchors.rightMargin: 30
        wrapMode: Text.WordWrap
        anchors.topMargin: 30
        anchors.leftMargin: 30
        fontSizeMode: Text.Fit
        font.pointSize: 400
        minimumPointSize: 1
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.AutoText
    }

    //Set the question. Why not binding? Because these variables will change for
    //each question, then if we binding it, it will always use the last question.
    Component.onCompleted: {
        answerButtonTxt.text = questionsDB.nextAnswer;
        answerButton.z = questionsDB.isRight;
    }
}
