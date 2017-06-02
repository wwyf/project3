a.exe:polynomial.cpp polynomial.h main.cpp data.cpp data.h
	g++ polynomial.cpp main.cpp data.cpp -std=c++11 -W -Wall -g
e:polynomial.cpp polynomial.h main.cpp data.cpp data.h
	g++ polynomial.cpp main.cpp data.cpp -std=c++11 -W -Wall -g
	./a.exe < in > out
	rm a.exe
t:
	g++ t.cpp polynomial.cpp -std=c++11 -W -Wall -g
	./a.exe
	rm a.exe
