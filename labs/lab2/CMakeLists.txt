project(write)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
add_executable(test lab2functions.cpp
  lab2.cpp)