start: complie run

complie:
	g++ -c ./include/max.hpp -o ./lib/max.o
	g++ -c ./include/node.hpp -o ./lib/node.o
	g++ -c ./include/fileRead.hpp -o ./lib/fileRead.o
	g++ -c ./include/incAll.hpp -o ./lib/incAll.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o
	g++  ./lib/main.o -o ./bin/main.exe
	
run:
	./bin/main.exe
