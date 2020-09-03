derlecalistir:output calistir

output:source.o node.o people.o
	g++ ./lib/source.o ./lib/node.o ./lib/people.o -o ./bin/output	
source.o:
	g++ -I "./include" -c ./src/source.cpp -o ./lib/source.o	
node.o:
	g++ -I "./include" -c ./src/node.cpp -o ./lib/node.o
people.o:
	g++ -I "./include" -c ./src/people.cpp -o ./lib/people.o
clean:
	rm *.o output
calistir:
	./bin/output