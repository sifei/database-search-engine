program: program.o patient.o Event.o
	g++ -o program program.o patient.o Event.o
program.o: program.cpp patient.h event.h
	g++ -Wall -c -g program.cpp
patient.o: patient.cpp patient.h
	g++ -Wall -c -g patient.cpp
event.o: event.cpp event.h
	g++ -Wall -c -g event.cpp
