##
# Lyra
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
	@$(CCX) $(OBJ) -o $(PROJECT) $(LDFLAGS)
	@echo "Compilation finished"

src/%.o: src/%.cpp
	@$(CCX) $(CCXFLAGS) -c $< -o $@

run:
	@echo "Running"
	@./$(PROJECT)
	@echo "Finished Running"

clean:
	@rm -f $(OBJ) $(PROJECT)
	@echo "Done"

setup:
	@which fltk-config >/dev/null 2>&1 || $(MAKE) _detect_install
	@echo "FLTK already installed, skipping setup."

_detect_install:
ifeq ($(shell [ -f /etc/debian_version ] && echo deb),deb)
	@echo "Installing FLTK on Debian/Ubuntu..."
	sudo apt update
	sudo apt install libfltk1.3-dev
else
ifeq ($(shell [ -f /etc/arch-release ] && echo arch),arch)
	@echo "Installing FLTK on Arch/Manjaro..."
	sudo pacman -Syu fltk
else
	@echo "Unsupported system. Please install FLTK manually :("
endif
endif

# end
