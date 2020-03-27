MODULE := modul1.o modul2.o modul3.o
PROGRAMME := programm1 programm2

programm1.o: programm1.c modul1.h modul2.h
	gcc -std=c99 -Wall -Wpedantic -c $<

programm2.o: programm2.c modul2.h modul3.h
	gcc -std=c99 -Wall -Wpedantic -c $<        

%.o : %.c %.h
	gcc -std=c99 -Wall -Wpedantic -c $<

programm1: programm1.o modul1.o modul2.o
	gcc -std=c99 -Wall -Wpedantic -o $@ $^

programm2: programm2.o modul2.o modul3.o
	gcc -std=c99 -Wall -Wpedantic -o $@ $^

