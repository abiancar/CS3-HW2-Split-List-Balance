all:
	g++ -Wall product-digit-sum.cpp -o dow

run:
	./dow

try: all run
