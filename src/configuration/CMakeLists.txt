FILE(GLOB_RECURSE configuration_SRC "*.hpp" "*.cpp")

MESSAGE("configuration_SRC: ")
FOREACH(fileSrc ${configuration_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

# SET (configuration_SRC
#   # add here both your sources (cpp) and header (hpp) files
#   FileParser.hpp
#   FileParser.cpp
#   )

ADD_LIBRARY(configuration STATIC ${configuration_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})