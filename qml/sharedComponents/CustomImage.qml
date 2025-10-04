import QtQuick 2.15
import "../styles"

Image {
    anchors.verticalCenter: parent.verticalCenter

    property string iconPath
    property bool iconVisible: true
    property real widthMultiplier: 1
    property real heightMultiplier: 1

    width: MyStyles.iconWidth * widthMultiplier
    height: MyStyles.iconHeight * heightMultiplier
    visible: iconVisible
    source: iconPath
}
