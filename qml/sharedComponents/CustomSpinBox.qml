import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
import "../styles"

SpinBox {
    width: parent.width

    property real inputValue
    property int toValue: 3000
    property color backgroundColor: MyStyles.backgroundColor
    property color borderColor: MyStyles.generalBorderColor

    background: Rectangle {
        width: parent.width
        height: parent.height
        radius: 21
        color: backgroundColor
        border.color: borderColor
        border.width: 1
    }

    value: inputValue
    from: 0
    to: toValue
    editable: true
    font.pixelSize: MyStyles.fontSize
}
