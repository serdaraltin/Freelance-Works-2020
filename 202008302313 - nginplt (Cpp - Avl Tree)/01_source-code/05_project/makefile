all:comp calistir

main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o	
dugum.o:
	g++ -I "./include" -c ./src/dugum.cpp -o ./lib/dugum.o
kisi.o:
	g++ -I "./include" -c ./src/kisi.cpp -o ./lib/kisi.o
comp:main.o dugum.o kisi.o
	g++ ./lib/main.o ./lib/dugum.o ./lib/kisi.o -o ./bin/main.exe
calistir:
	./bin/main.exe