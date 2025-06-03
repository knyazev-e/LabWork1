CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2
TARGET = run
PARALLEL_TARGET = parallel_run

SRCS = main.cpp Image.cpp
PARALLEL_SRCS = parallel_main.cpp Image.cpp
HEADERS = Image.h

OBJS = $(SRCS:.cpp=.o)
PARALLEL_OBJS = $(PARALLEL_SRCS:.cpp=.o)

all: $(TARGET) $(PARALLEL_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(PARALLEL_TARGET): $(PARALLEL_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PARALLEL_OBJS)  $(TARGET) $(PARALLEL_TARGET)
.PHONY: all clean
