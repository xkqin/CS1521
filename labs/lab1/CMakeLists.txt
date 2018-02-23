
project(TicTacToe)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable(tictactoe board.cpp game.cpp main.cpp player.cpp)