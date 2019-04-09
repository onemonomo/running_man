
source = ./main.cpp
header = .
compile_process : $(source) $(header)
	g++ AbstractPlayGround.cpp AbstractRunner.cpp main.cpp -o main.out
	./main.out
