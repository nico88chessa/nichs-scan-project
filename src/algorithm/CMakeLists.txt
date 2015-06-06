FILE(GLOB_RECURSE algorithm_SRC "*.hpp" "*.cpp")

MESSAGE("algorithm_SRC:")
FOREACH(fileSrc ${algorithm_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

ADD_LIBRARY(algorithm STATIC ${algorithm_SRC})
