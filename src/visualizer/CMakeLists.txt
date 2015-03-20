SET (visualizer_SRC
  # add here both your sources (cpp) and header (hpp) files
  EventHandler.hpp
  AbstractEvent.hpp
  AbstractEvent.cpp
  KeyboardHandler.hpp
  KeyboardHandler.cpp
  Visualizer.hpp
  Visualizer.cpp

  events/EventProva.hpp
  
#  events/EventProva.cpp
  )

ADD_LIBRARY(visualizer STATIC ${visualizer_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})
