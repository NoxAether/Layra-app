##
# Project Title
#
# @file
# @version 0.1
CCX = g++
CCXFLAGS = -std=c++23 -g -Wall
PROJECT = minesweeper
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(PROJECT): $(OBJ)
	$(CCX) $(OBJ) -o $(PROJECT)

src/%.o: src/%.cpp
	$(CXX) $(CCXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PROJECT)
# end
