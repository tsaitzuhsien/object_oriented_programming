CXXC := g++
CXXFLAGS := -std=c++11 -Wall -O2

.PHONY: all clean

TARGET := rational
OBJECTS := rational.o rational_main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
