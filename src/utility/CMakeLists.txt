FILE(GLOB_RECURSE utility_SRC "*.hpp" "*.cpp")

MESSAGE("utility_SRC: ")
FOREACH(fileSrc ${utility_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()


# SET (utility_SRC
#   # add here both your sources (cpp) and header (hpp) files
#   Utility.hpp
#   Utility.cpp
#   )

ADD_LIBRARY(utility STATIC ${utility_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})