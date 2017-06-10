import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.2

GridLayout {
    id: mainGrid
    visible: true
    rowSpacing: 70
    anchors.rightMargin: 73
    anchors.leftMargin: 73
    anchors.bottomMargin: 50
    anchors.topMargin: 50
    rows: 2
    columns: 1
    anchors.fill: background

    // Calculate the grid margin based on resolution.
    signal windowRisezedX()
    signal windowRisezedY()

    onWidthChanged: { windowRisezedX(); }
    onHeightChanged: { windowRisezedY(); }

    Rectangle {
        id: question
        width: 856
        height: 200
        color: "#ffffff"
        opacity: 0.8
        radius: 33
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.preferredHeight: 200
        Layout.preferredWidth: 856
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.row: 1
        Layout.column: 1
        Text{
            id: questionTxt
            text: questionsDB.nextQuestion
            z: 1
            anchors.rightMargin: 50
            anchors.leftMargin: 50
            anchors.bottomMargin: 50
            anchors.topMargin: 50
            textFormat: Text.AutoText
            scale: 1
            fontSizeMode: Text.Fit
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            anchors.fill: parent
            font.family: "Tahoma"
            font.pointSize: 400
            minimumPointSize: 1
        }
    }

    GridLayout {
        id: answerGrid
        width: 100
        height: 100
        Layout.preferredHeight: 250
        columnSpacing: 35
        rowSpacing: 35
        rows: 0
        columns: 2
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.row: 2
        Layout.column: 1

        Repeater{
            model: 4
            AnswerButton{}
        }
    }

    function calculeXMargin() {
        var margin = (height * 50) / 600;
        mainGrid.anchors.topMargin = margin;
        mainGrid.anchors.bottomMargin = margin;

        fitLayout();
    }

    function calculeYMargin() {
        var margin = (width * 73) / 1024;
        mainGrid.anchors.leftMargin = margin;
        mainGrid.anchors.rightMargin = margin;

        fitLayout();
    }

    // Adjust the layout to fit on screen.
    property bool landscape: true // Just to not "remake" the same thing all time.

    function fitLayout() {
        if(mainWindow.height > mainWindow.width && landscape) {
            answerGrid.columns = 1;
            answerGrid.rowSpacing = 15;

            landscape = false;
        }
        else if (mainWindow.height < mainWindow.width && !landscape){
            answerGrid.columns = 2;
            answerGrid.rowSpacing = 35;

            landscape = true;
        }
    }

    // Connect the signal on loading complete.
    Component.onCompleted: {
        mainGrid.windowRisezedX.connect(calculeXMargin);
        mainGrid.windowRisezedY.connect(calculeYMargin);

        calculeXMargin(); calculeYMargin()
    }
}
