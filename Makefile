##
# Minesweeper
#
# @file
# @version 0.1

CCX = g++
CCXFLAGS = -std=c++23 -O3 -Wall -flto $(shell fltk-config --cxxflags)
LDFLAGS = $(shell fltk-config --ldflags)

PROJECT = Lyra
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(PROJECT): $(OBJ)
	$(CCX) $(OBJ) -o $(PROJECT) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CCX) $(CCXFLAGS) -c $< -o $@

run:
	./$(PROJECT)

clean:
	rm -f $(OBJ) $(PROJECT)

# end
