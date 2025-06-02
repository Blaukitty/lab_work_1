CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iheaders

SRC_DIR := cpp_files
HDR_DIR := headers
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TARGET := $(BUILD_DIR)/game

.PHONY: all clean 

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

TEST_SRCS := $(wildcard tests/*.cpp)
TEST_OBJS := $(patsubst tests/%.cpp,$(BUILD_DIR)/%.test.o,$(TEST_SRCS))
TEST_EXEC := $(BUILD_DIR)/run_tests
LDLIBS    := -pthread -lgtest -lgtest_main

test: $(TEST_EXEC)
	@echo "Running unit tests..."
	@$(TEST_EXEC)

$(BUILD_DIR)/%.test.o: tests/%.cpp $(filter-out $(BUILD_DIR)/main.o,$(OBJS)) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJS) $(filter-out $(BUILD_DIR)/main.o,$(OBJS)) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -rf $(BUILD_DIR)
