// https://www.rapidtables.com/web/color/RGB_Color.html

pragma Singleton
import QtQuick

QtObject {
    property string rootPath:       Qt.resolvedUrl("../../")

    // *** GENERAL SETTINGS ***
    property color backgroundColor: "#0A0A0A"
    property color linesColor:      "#000000"
    property color ribbonColor:     "#000007"
    property string fontStyle:      "Courier New"
    property int fontSize:          16
    property color fontColor:       "#C2C2D1"

    // *** CARDS PROPERIES ***
    property color cardsBackgroundColor: "#000000"
    property color mediumRectangleBgColor: "#161617"
    property color smallRectangleBgColor: "#222224"

    // *** LIST PROPERIES ***
    property color listLineColor: "#000000"
    property real listLineHeight: 1

    // *** FOLDERS PATHS ***
    property string assetsPath: rootPath + "assets/"

    // *** ICONS SETTINGS & PATHS ***
    property real iconWidth: 30
    property real iconHeight: 30

    property string sideMenuIcon: rootPath + "assets/menu-bar.png"
    property string chartsIcon: rootPath + "assets/analysis.png"
    property string userIcon: rootPath + "assets/user.png"
    property string homeIcon: rootPath + "assets/house.png"
    property string exampleChartImage: rootPath + "assets/example-eegchart-with4channels.png"


}
