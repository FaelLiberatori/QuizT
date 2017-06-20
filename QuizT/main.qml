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

    BackgroundAnim {}

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
