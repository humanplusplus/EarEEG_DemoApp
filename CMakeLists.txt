cmake_minimum_required(VERSION 3.16)
project(appEarEEG_DemoApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS REQUIRED Core Gui Qml Quick Charts Sql Network)

qt_add_executable(appEarEEG_DemoApp
    main.cpp

    src/database/DatabaseConfig.h
    src/database/TableSchemasSQLite.h

    src/database/IDataManager.h
    src/database/SQLiteManager.h
    src/database/SQLiteManager.cpp
    src/database/DataHandler.h
    src/database/DataHandler.cpp
    src/database/DatabaseManager.h
    src/database/DatabaseManager.cpp
)

set_source_files_properties(
    qml/styles/MyStyles.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE TRUE
)

# qt_policy(SET QTP0004 NEW)
qt_add_qml_module(appEarEEG_DemoApp
    URI EarEEG_DemoApp
    VERSION 1.0
    QML_FILES
        main.qml
        qml/styles/MyStyles.qml

        qml/screens/DataScreen.qml
        qml/screens/HomeScreen.qml
        qml/screens/UserDetailsScreen.qml
        qml/screens/UserDetailsInputDialog.qml

        qml/sharedComponents/CustomLabel.qml
        qml/sharedComponents/CustomTextField.qml
        qml/sharedComponents/ButtonWithText.qml
        qml/sharedComponents/DialogBackgroundField.qml
        qml/sharedComponents/CustomRadioButton.qml
        qml/sharedComponents/CustomSpinBox.qml
        qml/sharedComponents/CustomImage.qml
        qml/sharedComponents/LineSeparator.qml
        qml/sharedComponents/TabButtonFooter.qml
        qml/sharedComponents/ListText.qml

        qml/earEegComponents/ScopeView.qml
        qml/earEegComponents/ControlPanel.qml
        qml/earEegComponents/MultiButton.qml
        qml/earEegComponents/FocusRecommendations.qml

    IMPORTS
        QtCharts

    RESOURCES
        assets/analysis.png
        assets/light-bulb.png
        assets/arrow.png
        assets/arrow-up.png
        assets/down.png
        assets/gear.png
        assets/right-arrow.png
        assets/settings.png
        assets/top.png
        assets/dots.png
        assets/user.png
        assets/home.png
        assets/home1.png
        assets/house.png
        assets/menu-bar.png
        assets/EarEEG.png
        assets/example-eegchart-with4channels.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appEarEEG_DemoApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appEarEEG_DemoAppFrontend
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appEarEEG_DemoApp
    PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::Charts Qt6::Sql Qt6::Network)

include(GNUInstallDirs)
install(TARGETS appEarEEG_DemoApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
