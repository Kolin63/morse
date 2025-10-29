CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Iinclude -MMD -MP

SRC_DIR := src
BUILD_DIR := build

LISTER_SRCS := $(wildcard $(SRC_DIR)/lister/*.cpp)
LISTER_OBJS := $(patsubst $(SRC_DIR)/lister/%.cpp,$(BUILD_DIR)/lister_%.o,$(LISTER_SRCS))

CHECKER_SRCS := $(wildcard $(SRC_DIR)/checker/*.cpp)
CHECKER_OBJS := $(patsubst $(SRC_DIR)/checker/%.cpp,$(BUILD_DIR)/checker_%.o,$(CHECKER_SRCS))

LISTER_TARGET := lister
CHECKER_TARGET := checker

DEPS := $(COMMON_OBJS:.o=.d) $(LISTER_OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

all: $(LISTER_TARGET) $(CHECKER_TARGET)

$(LISTER_TARGET): $(COMMON_OBJS) $(LISTER_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(CHECKER_TARGET): $(COMMON_OBJS) $(CHECKER_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/common_%.o: $(SRC_DIR)/common/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/lister_%.o: $(SRC_DIR)/lister/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/checker_%.o: $(SRC_DIR)/checker/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(LISTER_TARGET) $(CHECKER_TARGET)

.PHONY: all clean
