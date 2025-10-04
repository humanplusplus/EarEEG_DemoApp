import QtQuick 2.15
import QtQuick.Controls
import "../styles"

Text {
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter

    property string innerText

    text: innerText
    font.pixelSize: MyStyles.fontSize
    color: MyStyles.backgroundColor
}
