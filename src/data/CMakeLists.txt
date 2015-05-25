FILE(GLOB_RECURSE data_SRC "*.hpp" "*.cpp")

MESSAGE("data_SRC: ")
FOREACH(fileSrc ${data_SRC})
  MESSAGE(${fileSrc})
ENDFOREACH()

ADD_LIBRARY(data STATIC ${data_SRC})