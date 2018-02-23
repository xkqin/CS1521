project(lab6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLGS} -Wall -std=c++11")

add_executable(test lab6.cpp PrecondViolatedExcep.cpp Rational.cpp)