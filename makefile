# Baldwin, Josiah
# 2019/12/24

CXX=g++
CXXFLAGS=-g -std=c++17
TARGET=test

all: $(TARGET)

clean:
	rm $(TARGET)

$(TARGET): test_main.cpp vector2.hpp
	$(CXX) $(CXXFLAGS) $< -o $@
