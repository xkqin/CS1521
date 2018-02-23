project(project6)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
add_executable(test Event.cpp EventBuilder.cpp  Simulation.cpp 
                project6.cpp Statistics.cpp PrecondViolatedExcep.cpp)