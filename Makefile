# Makefile for the LMS
# Daniel Teberian

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude


SRC := src
OBJ := obj


SRCS := $(wildcard $(SRC)/*.cpp)
OBJS := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))


TARGET := lms


all:	$(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@


$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@


