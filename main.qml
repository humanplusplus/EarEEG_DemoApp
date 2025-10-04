import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Controls.Fusion
import "qml/styles"
import "./qml/sharedComponents"

ApplicationWindow {
    visible: true
    width: 360
    height: 640

    // // Screens paths
    property string userDetailsScreenPath:  MyStyles.rootPath + "qml/screens/UserDetailsScreen.qml"
    property string dataScreenPath:         MyStyles.rootPath + "qml/screens/DataScreen.qml"
    property string homeScreenPath:         MyStyles.rootPath + "qml/screens/HomeScreen.qml"

    // Menus titles
    property string headerTitle:            "Attention"
    property string homeTitle:              "Home"
    property string dataTitle:              "EarEEG Data"
    property string userDetailsTitle:       "User Details"

    Material.accent: "transparent"
    background: Rectangle {
        color: MyStyles.backgroundColor
    }

    header: ToolBar {
        contentHeight: 60
        background: Rectangle {
            color: MyStyles.ribbonColor
        }

        Row {
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            // Left side header
            ToolButton {
                hoverEnabled: false
                highlighted: false

                // Rectangle {
                //     width: 30
                //     height: 30
                //     radius: 5
                //     color: MyStyles.smallRectangleBgColor
                //     anchors.verticalCenter: parent.verticalCenter

                //     ImageIcons {
                //         iconPath: MyStyles.sideMenuIcon
                //     }
                // }

                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    if (drawer.visible) {
                        drawer.close()
                    } else {
                        drawer.open()
                    }
                }
            }

            // Transparent space to center
            Rectangle {
                width: parent.width * 0.25
                height: 1
                color: "transparent"
            }

            // Middle side header
            Row {
                spacing: 5
                anchors.centerIn: parent

                Label {
                    id: headerLabel
                    text: headerTitle
                    color: MyStyles.fontColor
                    font.pointSize: MyStyles.fontSize
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            // Transparent space to center
            Rectangle {
                width: parent.width * 0.25
                height: 1
                color: "transparent"
            }

            // Right side header
            ToolButton {
                id: homeButton
                visible: false

                hoverEnabled: false
                highlighted: false

                // ImageIcons {
                //     iconPath: MyStyles.homeIcon
                // }

                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    headerLabel.text = headerTitle
                    homeButton.visible = false
                    stackView.push(userDetailsScreenPath)
                    footer.visible = true
                }
            }
        }

        // Line on the top of the header
        LineSeparator {
            lineHeight: 2
            lineColor: MyStyles.linesColor
        }
    }

    // // Side menu
    // Drawer {
    //     id: drawer
    //     width: parent.width * 0.5
    //     height: parent.height
    //     edge: Qt.LeftEdge

    //     background: Rectangle {
    //         color: MyStyles.cardsBackgroundColor
    //     }

    //     ListView {
    //         width: parent.width
    //         height: parent.height
    //         model: [
    //             homeTitle,
    //             dataTitle,
    //             userDetailsTitle
    //         ]
    //         delegate: ItemDelegate {
    //             width: parent.width
    //             height: 50

    //             contentItem: Text {
    //                 anchors.left: parent.left
    //                 anchors.leftMargin: 10
    //                 text: modelData
    //                 font.pointSize: MyStyles.fontSize
    //                 color: MyStyles.fontColor
    //             }

    //             highlighted: false
    //             hoverEnabled: false

    //             LineSeparator {
    //                 lineColor: MyStyles.linesColor
    //                 lineHeight: 1
    //             }

    //             MouseArea {
    //                 anchors.fill: parent
    //                 onClicked: {
    //                     drawer.close()
    //                     if (modelData === homeTitle) {
    //                         homeButton.visible = true
    //                         headerLabel.text = homeTitle
    //                         stackView.push(userDetailsScreenPath)
    //                         footer.visible = false
    //                     } else if (modelData === dataTitle) {
    //                         homeButton.visible = true
    //                         headerLabel.text = dataTitle
    //                         stackView.push(dataScreenPath)
    //                         footer.visible = false
    //                     } else if (modelData === userDetailsTitle) {
    //                         homeButton.visible = true
    //                         headerLabel.text = userDetailsTitle
    //                         stackView.push(Qt.resolvedUrl(homeScreenPath))
    //                         footer.visible = false
    //                     } else {
    //                         stackView.push(Qt.resolvedUrl(userDetailsScreenPath), { category: modelData })
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: homeScreenPath

        onCurrentItemChanged:
            tabBar.visible = !(stackView.currentItem instanceof HomeScreen)
    }

    footer: TabBar {
        id: footer
        height: 50

        background: Rectangle {
            color: MyStyles.ribbonColor
        }

        TabButtonFooter {
            stackViewPath: Qt.resolvedUrl(homeScreenPath)
            iconPath: MyStyles.homeIcon
        }

        TabButtonFooter {
            stackViewPath: Qt.resolvedUrl(dataScreenPath)
            iconPath: MyStyles.chartsIcon
        }

        TabButtonFooter {
            stackViewPath: Qt.resolvedUrl(userDetailsScreenPath)
            iconPath: MyStyles.userIcon
        }
    }
}
