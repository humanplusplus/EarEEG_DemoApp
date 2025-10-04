import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
import "../styles"

TextField {
    width: parent.width
    height: 40

    property string innerText
    property string placeholderInnerText
    property int maxTextLength: 40
    property color backgroundColor: MyStyles.mediumRectangleBgColor
    property color borderColor: MyStyles.linesColor

    background: Rectangle {
        width: parent.width
        height: parent.height
        radius: 21
        color: backgroundColor
        border.color: borderColor
        border.width: 1
    }

    text: innerText
    horizontalAlignment: Text.AlignLeft
    verticalAlignment: Text.AlignLeft
    placeholderText: placeholderInnerText
    font.pixelSize: MyStyles.fontSize
    color: MyStyles.fontColor
    maximumLength: maxTextLength
}
