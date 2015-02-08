CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(imageSegmentation)

FIND_PACKAGE(CUDA REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Boost 1.57 REQUIRED program_options)

SET (MY_LIBS ${MY_LIBS} ${Boost_LIBRARIES})

INCLUDE_DIRECTORIES(/usr/local/cuda/include)

SET(MY_FOLDERS
  configuration
  utility
  )

FOREACH(dir ${MY_FOLDERS})
  ADD_SUBDIRECTORY(${dir})    # processa i CMakeLists.txt nelle directory
  INCLUDE_DIRECTORIES(${dir}) # per far trovare a cmake i file header
ENDFOREACH(dir)

#add_executable(main main.cpp)
# CUDA_ADD_EXECUTABLE(main main.cpp)

#ADD_EXECUTABLE(main main.cpp)
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main ${MY_FOLDERS} ${MY_LIBS})