# Baldwin, Josiah
# 2019/12/24

CXX=g++
CXXFLAGS=-g -std=c++17
TARGET=test
HEADERS=*.hpp

all: $(TARGET)

clean:
	rm $(TARGET)

$(TARGET): test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@
