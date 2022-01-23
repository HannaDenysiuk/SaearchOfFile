
output: main.o SearchOfFile.o
	g++ main.o SearchOfFile.o -o output

main.o: main.cpp
	g++ -c main.cpp
	
SearchOfFile.o: SearchOfFile.cpp SearchOfFile.h
	g++ -c SearchOfFile.cpp 
	
clean:
	rm *.o output