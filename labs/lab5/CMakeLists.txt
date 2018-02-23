project(lab5)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
add_executable(test main.cpp isPalindrome.cpp PrecondViolatedExcep.cpp)