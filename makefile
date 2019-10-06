all:
	g++ main.cpp Animal.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp -o zooMain
clean:
	rm zooMain