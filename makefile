hw2: hw2.o
	g++ hw2.o -o hw2
	./hw2
hw2.o: hw2.cpp
	g++ hw2.cpp -c
clean:
	rm -rf hw2.o 
