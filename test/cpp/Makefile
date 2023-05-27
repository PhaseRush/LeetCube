TESTS = $(wildcard test_*.cpp)
OUT = $(basename $(TESTS))

CXX = clang++
CXXFLAGS = -std=c++17 -g -O2 -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined
CATCH_CXXFLAGS = -std=c++17 -c -g -Ofast -march=native -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined

all: $(OUT)

run: $(OUT)
	@for t in $(OUT); do ./$$t; done

cpp_deps/catch_config.o: cpp_deps/catch_config.cpp
	$(CXX) $(CATCH_CXXFLAGS) $^ -o $@

$(OUT): test_%: ../../src/cpp/code_%.cpp test_%.cpp cpp_deps/catch_config.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OUT)

.PHONY: all clean