import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../sharedComponents"
import "../earEegComponents"
import "../styles"

Page {
    id: root
    anchors.fill: parent

    FocusRecommendations {
        id: recs
    }

    property int currentFocusLevel: 1
    property int currentFocusPercent: 0
    property var currentRec: recs.byLevel(currentFocusLevel)
    property string titleText: "Current Score"
    property string buttonText: "ADD NOTES"
    property string loadingDataText: "Loading data..."
    property string titleHowToHangeText: "How to change it?"

    background: Rectangle {
        color: "transparent"
    }

    // ---------------------------
    // Generowanie losowych liczb, które określają poziom skupienia (dopóki backend nie będzie gotowy)
    // ---------------------------
    Timer {
        interval: 3000
        running: true
        repeat: true
        // onTriggered: root.currentFocusLevel = Math.floor(Math.random() * 3) + 1

        onTriggered: {
            // losowy poziom (1–3)
            root.currentFocusLevel = Math.floor(Math.random() * 3) + 1

            // pobranie zakresu dla danego poziomu
            var rec = recs.byLevel(root.currentFocusLevel)
            if (rec) {
                var min = rec.minPercent
                var max = rec.maxPercent
                // losowa liczba z zakresu
                root.currentFocusPercent = Math.floor(Math.random() * (max - min + 1)) + min
            }
        }
    }

    // ---------------------------
    // Przypięta stopka z przyciskiem
    // ---------------------------
    ButtonWithText {
        id: notesButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16
        buttonText: "ADD NOTES"
        z: 10
    }

    // ---------------------------
    // Nagłówek i opis
    // ---------------------------
    Column {
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10
        spacing: 15

        Column {
            width: parent.width * 0.9
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            // Text {
            //     text: currentRec ? currentRec.description : loadingDataText
            //     color: MyStyles.fontColor
            //     font.pixelSize: 18
            //     font.bold: true
            //     horizontalAlignment: Text.AlignHCenter
            //     wrapMode: Text.WordWrap
            //     anchors.horizontalCenter: parent.horizontalCenter
            // }

            // Text {
            //     text: currentRec ? currentRec.detailedDescription : ""
            //     color: MyStyles.fontColor
            //     font.pixelSize: 18
            //     horizontalAlignment: Text.AlignHCenter
            //     wrapMode: Text.WordWrap
            //     anchors.horizontalCenter: parent.horizontalCenter
            //     width: parent.width
            //     maximumLineCount: 4
            //     elide: Text.ElideRight
            // }
        }

        // ---------------------------
        // Karta z detalami i poziomem
        // ---------------------------
        Rectangle {
            width: parent.width
            height: 100
            color: MyStyles.mediumRectangleBgColor
            radius: 12

            Column {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 7

                // napis na górze
                Text {
                    text: titleText
                    color: "transparent" // currentRec ? currentRec.color : MyStyles.fontColor
                    font.pixelSize: 10
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                // wiersz z % i ikonką
                Row {
                    spacing: 12
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: currentFocusPercent + "%" //currentRec ? currentRec.focusPercentage : "--"
                        color: currentRec ? currentRec.color : MyStyles.fontColor
                        font.pixelSize: 40
                        font.bold: true
                    }

                    Rectangle {
                        width: 34
                        height: 34
                        radius: 6
                        color: MyStyles.smallRectangleBgColor
                        anchors.verticalCenter: parent.verticalCenter

                        CustomImage {
                            anchors.centerIn: parent
                            iconPath: currentRec ? (root.MyStyles.assetsPath + currentRec.arrowIconFileName) : ""
                            widthMultiplier: 1
                            heightMultiplier: 1
                            fillMode: Image.PreserveAspectFit
                        }
                    }
                }
            }
        }

        // ---------------------------
        // WYKRES EEG (PNG) - do podmienienia na prawdziwy
        // ---------------------------

        Column {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 8

            Rectangle {
                width: parent.width
                height: 120
                color: "transparent"

                CustomImage {
                    anchors.horizontalCenter: parent.horizontalCenter
                    iconPath: root.MyStyles.exampleChartImage
                    widthMultiplier: 12
                    heightMultiplier: 5
                }
            }
        }


        // ---------------------------
        // Lista rekomendacji
        // ---------------------------
        Column {
            width: parent.width * 0.9
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
            spacing: 8

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: currentRec ? currentRec.recommendationTitle : ""
                color: MyStyles.fontColor
                font.pixelSize: 18
                font.bold: true
            }

            Repeater {
                model: currentRec ? currentRec.recommendations : []
                delegate: Text {
                    width: parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.Wrap
                    text: "• " + modelData
                    color: MyStyles.fontColor
                    font.pixelSize: 18
                }
            }
        }
    }
}
