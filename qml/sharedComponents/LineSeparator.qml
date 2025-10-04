import QtQuick 2.15
import "../styles"

Rectangle {
    width: parent.width
    anchors.bottom: parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter

    property real lineHeight
    property color lineColor

    color: lineColor
    height: lineHeight // Line thickness
}
