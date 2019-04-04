
source = ./main.cpp
header = .
compile_process : $(source) $(header)
	g++ main.cpp -o main.out
	./main.out
