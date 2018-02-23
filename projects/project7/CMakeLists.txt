project(project7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable(test PrecondViolatedExcep.cpp main.cpp NotFoundException.cpp)