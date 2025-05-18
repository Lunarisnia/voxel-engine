run:
	cmake . -DCMAKE_BUILD_TYPE=debug -B ./build
	cmake --build ./build/
	./build/debug/VoxelEngine
test:
	clang++ --debug ./src/main.cpp ./src/**/*.c -I/usr/local/include -L/usr/local/lib -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit --std=c++17 -o ./build/test
	./build/test
