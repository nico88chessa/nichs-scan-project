# QT5_WRAP_UI(UIS_HEADERS mainwindow.ui ImageViewerForm.ui)

FILE(GLOB_RECURSE qt_SRC "*.hpp" "*.cpp" "*.h")

MESSAGE("qt_SRC: ")
FOREACH(fileSrc ${qt_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_LIBRARY(qt STATIC ${UIS_HEADERS} ${qt_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})

