CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pthread

TARGET = order_matching

SRC = main.cpp order_book.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)