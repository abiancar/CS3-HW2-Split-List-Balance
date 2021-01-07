all:
	g++ -Wall product-digit-sum.cpp -o sum

run:
	./sum

try: all run
