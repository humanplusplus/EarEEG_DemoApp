import QtQuick 2.15
import QtQuick.Controls.Material
import "../styles"

Rectangle {
    width: parent.width
    height: parent.height

    property color backgroundColor: MyStyles.dialogBackgroundColor
    property color borderColor: MyStyles.generalBorderColor

    radius: 21
    color: backgroundColor
    border.color: borderColor
    border.width: 2
}
