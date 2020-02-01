# Baldwin, Josiah
# 2019/12/24

CXX=g++
CXXFLAGS=-g -std=c++17
TARGET=test
HEADERS=*.hpp
.PHONY=all clean run test_lib

all: $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Force compile, than run, then clean.
test_lib: clean run
	rm -f $(TARGET)

$(TARGET): test.cpp include/$(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@
