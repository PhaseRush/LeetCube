SRCS_DIR = src/cpp
TESTS_DIR = test/cpp
TESTS = $(wildcard $(TESTS_DIR)/test_*.cpp)
BUILD_DIR = build
BIN_DIR = bin
OUT = $(subst $(TESTS_DIR), $(BIN_DIR), $(basename $(TESTS)))

CXX = clang++
CXXFLAGS = -std=c++17 -g -O2 -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined
CATCH_CXXFLAGS = -std=c++17 -c -g -Ofast -march=native -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined

all: $(OUT)

run: $(OUT)
	@for t in $(OUT); do ./$$t; done

$(BUILD_DIR)/catch_config.o: $(TESTS_DIR)/cpp_deps/catch_config.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CATCH_CXXFLAGS) $^ -o $@

$(OUT): $(BIN_DIR)/test_%: $(SRCS_DIR)/code_%.cpp $(TESTS_DIR)/test_%.cpp $(BUILD_DIR)/catch_config.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean