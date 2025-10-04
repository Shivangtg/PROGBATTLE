CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Ibots
TARGET = progbattle
SRCS = $(wildcard src/*.cpp) $(wildcard bots/*.cpp)
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build complete! Run with ./${TARGET}"

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf obj $(TARGET)

.PHONY: all clean