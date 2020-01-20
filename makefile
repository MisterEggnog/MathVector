# Baldwin, Josiah
# 2019/12/24

CXX=g++
CXXFLAGS=-g -std=c++17
TARGET=test

all: $(TARGET)

clean:
	rm $(TARGET)

$(TARGET): test.cpp vector2.hpp vector3.hpp vector.hpp
	$(CXX) $(CXXFLAGS) $< -o $@
