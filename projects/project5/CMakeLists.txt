project(project5)
set (CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall -std=c++11")
add_executable(test Disc.cpp main.cpp DiscList.cpp Track.cpp PrecondViolatedExcep.cpp)