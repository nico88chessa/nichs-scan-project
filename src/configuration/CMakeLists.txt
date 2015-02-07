SET (configuration_SRC
  # add here both your sources (cpp) and header (hpp) files
  FileParser.hpp
  FileParser.cpp
  )

ADD_LIBRARY(configuration STATIC ${configuration_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})