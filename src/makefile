path = ./../bin
$(path)/calculator.exe:polynomial.cpp polynomial.h main.cpp data.cpp data.h
	g++ polynomial.cpp main.cpp data.cpp -std=c++11 -W -Wall -g -o $(path)/calculator.exe
t:
	g++ t.cpp polynomial.cpp -std=c++11 -W -Wall -g
	./a.exe
	rm a.exe
