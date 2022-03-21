.PHONY: all clean run

all: clean run

clean:
	rm -rf build

run: build/toothpick

build/toothpick:
	mkdir -p build
	g++ -Wall -std=c++11 src/*.cpp -lSDL2 -o build/toothpick

run:
	./build/toothpick
