FILE(GLOB_RECURSE threading_SRC "*.hpp" "*.cpp")

MESSAGE("threading_SRC: ")
FOREACH(fileSrc ${threading_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

# SET (threading_SRC
#   # add here both your sources (cpp) and header (hpp) files
#   ControllerCyclicRunnable.cpp
#   ControllerCyclicRunnable.hpp
#   CyclicRunnable.cpp
#   CyclicRunnable.hpp
#   Runnable.hpp
#   ThreadController.cpp
#   ThreadController.hpp
#   )

ADD_LIBRARY(threading STATIC ${threading_SRC})
# TARGET_LINK_LIBRARIES(configuration ${MY_LIBS})

