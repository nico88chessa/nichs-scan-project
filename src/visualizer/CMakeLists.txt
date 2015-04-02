FILE(GLOB_RECURSE visualizer_SRC "*.hpp" "*.cpp")

MESSAGE("visualzer_SRC:")
FOREACH(fileSrc ${visualizer_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

# SET (visualizer_SRC
#   # add here both your sources (cpp) and header (hpp) files
#   AbstractEvent.hpp
#   AbstractEvent.cpp
  
#   KeyboardHandler.hpp
#   EventHandler.hpp
#   KeyboardHandler.cpp
#   IOVisualizer.hpp
#   IOVisualizer.cpp
#   Visualizer.cpp
#   Visualizer.hpp

#   events/NextImageEvent.hpp
#   events/EventProva.hpp
#   events/EventProva.cpp
#   )

ADD_LIBRARY(visualizer STATIC ${visualizer_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})
