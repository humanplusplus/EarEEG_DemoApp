import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
import "../styles"

Button {
    width: 120

    property string buttonText: "Confirm"
    property color innerColor: MyStyles.cardsBackgroundColor
    property color borderColor: MyStyles.linesColor
    property bool fontBold: false
    property real fontMultiplier: 1
    property real rectangleHeightMultiplier: 1
    property real rectangleWidthMultiplier: 1

    background: Rectangle {
        width: parent.width * rectangleWidthMultiplier
        height: 40 * rectangleHeightMultiplier
        radius: 21
        color: innerColor
        border.color: borderColor
        border.width: 1
    }

    contentItem: Text {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
        text: buttonText
        color: MyStyles.fontColor
        font.pixelSize: MyStyles.fontSize * fontMultiplier
        font.bold: fontBold
    }
}
