CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iheaders

SRC_DIR := cpp_files
HDR_DIR := headers
TEST_DIR := tests
BUILD_DIR := build

TARGET := $(BUILD_DIR)/game
TEST_EXEC := $(BUILD_DIR)/run_tests

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
# При сборке тестов мы будем линковать объекты из основного кода + gtest
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.test.o,$(TEST_SRCS))

LDLIBS := -pthread -lgtest -lgtest_main

.PHONY: all clean test

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.cpp $(filter-out $(BUILD_DIR)/main.o,$(OBJS)) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJS) $(filter-out $(BUILD_DIR)/main.o,$(OBJS)) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

test: $(TEST_EXEC)
	@echo "Running unit tests..."
	@$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)
