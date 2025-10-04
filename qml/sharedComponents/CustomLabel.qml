import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
import "../styles"

Label {
    width: parent.width

    property string labelText
    property bool textBold: false
    property real textSize: MyStyles.fontSize
    property color textColor: MyStyles.fontColor

    horizontalAlignment: Text.AlignLeft
    text: labelText
    font.pixelSize: textSize
    font.bold: textBold
    color: textColor
}
