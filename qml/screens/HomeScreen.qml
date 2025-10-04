import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "../styles"
import "../sharedComponents"

Page {
    id: pageItem
    padding: 50

    property int rowWidth: 150
    property int rowHeight: 80
    property string earEEGImage: MyStyles.rootPath + "assets/EarEEG.png"
    property string buttonInnerText: "Let's Focus!"
    property string dataScreenPath: MyStyles.rootPath + "DataScreen.qml"

    background: Rectangle {
        color: MyStyles.backgroundColor
    }

    CustomImage {
        anchors.centerIn:  parent
        fillMode: Image.PreserveAspectFit
        widthMultiplier: 14
        heightMultiplier: 14
        iconPath: earEEGImage
    }


    // Item {
    //     width: parent.width
    //     height: parent.height - 10

    //     ButtonWithText {
    //         anchors.bottom: parent.bottom
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         innerColor: MyStyles.cardsBackgroundColor
    //         buttonText: buttonInnerText
    //         fontBold: true

    //         onClicked: { stackView.push(Qt.resolvedUrl(dataScreenPath)) }
    //     }
    // }
}
