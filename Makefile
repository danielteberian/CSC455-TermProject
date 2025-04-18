# Makefile for the LMS
# Daniel Teberian

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g


SRC = src/main.cpp src/userman.cpp src/userman.h
OBJ = $(SRC:.cpp=.o)
TARGET = lms


OBJ_DIR = obj
# If it doesn't exist, make it
$(shell mkdir -p $(OBJ_DIR))
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))



$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)


$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ_DIR) $(TARGET)
