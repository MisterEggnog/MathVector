# Baldwin, Josiah
# 2019/12/24

CXX=g++
CXXFLAGS=-g -std=c++17
TARGET=test
HEADERS=*.hpp

all: $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): test.cpp include/$(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@
