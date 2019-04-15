
source = ./main.cpp
header = -I ./common -I ./abstract -I ./player -I ./weapon -I ./skill
compile_process : $(source)
	g++ $(header) ./abstract/AbstractPlayGround.cpp ./abstract/AbstractRunner.cpp main.cpp -o main.out
	./main.out
