all:
	g++ -Wall product-digit-sum.cpp -o sum
	g++ -Wall split-list-balance.cpp -o split

run:
	./sum

run2:
	./split

try: all run

try2: all run2

