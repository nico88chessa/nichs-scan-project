CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(imageSegmentation)

FIND_PACKAGE(CUDA REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Boost 1.57 REQUIRED program_options thread system)

SET (MY_LIBS ${MY_LIBS} ${Boost_LIBRARIES} ${OpenCV_LIBS})

INCLUDE_DIRECTORIES(/usr/local/cuda/include)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

# MESSAGE ("test: " ${OpenCV_INCLUDE_DIRS} )
# MESSAGE ("MY_LIBS: " ${MY_LIBS} )
# MESSAGE ("OPENCV_LIBS: " ${OpenCV_LIBS} )

SET(MY_FOLDERS
  configuration
  threading
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

ADD_EXECUTABLE(main2 main2.cpp)
TARGET_LINK_LIBRARIES(main2 ${MY_FOLDERS} ${MY_LIBS})