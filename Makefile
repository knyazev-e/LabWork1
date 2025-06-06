CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2
TESTFLAGS = -lgtest -pthread

TARGET = run
PARALLEL_TARGET = parallel_run
TEST_TARGET = Testing/tests

SRCS = main.cpp Image.cpp
PARALLEL_SRCS = parallel_main.cpp Image.cpp
TEST_SRCS = Testing/test.cpp Image.cpp
HEADERS = Image.h

OBJS = $(SRCS:.cpp=.o)
PARALLEL_OBJS = $(PARALLEL_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET) $(PARALLEL_TARGET) test

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(PARALLEL_TARGET): $(PARALLEL_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TESTFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PARALLEL_OBJS) $(TEST_OBJS) $(TARGET) $(PARALLEL_TARGET) $(TEST_TARGET)
.PHONY: all test clean
