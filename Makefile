# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -pedantic -Weffc++
SDL2FLAGS = `sdl2-config --cflags --libs`

# Target binary and source files
TARGET = chip8
SOURCES = main.cpp chip8.cpp platform.cpp

# Build target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(SDL2FLAGS)

# Clean target
clean:
	rm -f $(TARGET)
