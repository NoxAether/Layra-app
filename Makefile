##
# Lyra
# @file
# @version 0.2
##

# Compiler and flags
CCX = g++
CCXFLAGS = -std=c++23 -O3 -Wall -flto $(shell fltk-config --cxxflags)
LDFLAGS = $(shell fltk-config --ldflags)

# Project
PROJECT = Lyra

# Source files
SRC := $(wildcard src/*.cpp) \
       $(wildcard src/screens/*.cpp) \
       $(wildcard src/utils/*.cpp)

# Object files
OBJ := $(SRC:.cpp=.o)

# Default target
all: $(PROJECT)

# Link
$(PROJECT): $(OBJ)
	@echo "Linking..."
	$(CCX) $(OBJ) -o $(PROJECT) $(LDFLAGS)
	@echo "Build finished."

# Compile .cpp -> .o
%.o: %.cpp
	@echo "Compiling $< ..."
	$(CCX) $(CCXFLAGS) -c $< -o $@

# Run the program
run: $(PROJECT)
	@echo "Running $(PROJECT)..."
	./$(PROJECT)
	@echo "Finished."

# Clean up
clean:
	@rm -f $(OBJ) $(PROJECT)
	@echo "Cleaned."

# Setup FLTK
setup:
	@which fltk-config >/dev/null 2>&1 || $(MAKE) _detect_install
	@echo "FLTK already installed, skipping setup."

_detect_install:
ifeq ($(shell [ -f /etc/debian_version ] && echo deb),deb)
	@echo "Installing FLTK on Debian/Ubuntu..."
	sudo apt update
	sudo apt install -y libfltk1.3-dev
else
ifeq ($(shell [ -f /etc/arch-release ] && echo arch),arch)
	@echo "Installing FLTK on Arch/Manjaro..."
	sudo pacman -Syu fltk --noconfirm
else
	@echo "Unsupported system. Please install FLTK manually :("
endif
endif
