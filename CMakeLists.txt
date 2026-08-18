cmake_minimum_required(VERSION 3.16)

project(course VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(course
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


        report_directory.h report_directory.cpp report_directory.ui
        hash_table/DataManagerHashTable.h hash_table/hash_table.h hash_table/IHashTableIndex.h hash_table/IHashTableManager.h tree/DataManagerTree.h tree/I_tree.h tree/IDataManagerTree.h tree/rb_tree.h
        DataService.h StaticArray.h
        IStorage.h list.h Pair.h report_directory.h structures.h
        structures.cpp
        report_table_model.h
        report_table_model.cpp
        input_report_dialog.h input_report_dialog.cpp input_report_dialog.ui
        window_show_structures.h window_show_structures.cpp window_show_structures.ui
        validate_structures.h
        validate_stuctures.cpp
        show_table_view.h show_table_view.cpp show_table_view.ui
        investigation_directory.h investigation_directory.cpp investigation_directory.ui
        investigation_table_model.h
        investigation_table_model.cpp
        input_investigation_dialog.h input_investigation_dialog.cpp input_investigation_dialog.ui
        filter_dialog.h filter_dialog.cpp filter_dialog.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET course APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(course SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(course WIN32
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(course PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.course)
endif()
set_target_properties(course PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS course
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(course)
endif()
