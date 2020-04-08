#declare variables
CC = g++

CFLAGS = -c -w



all: app1 app2 app4 app5 app6

app1: app1.o					#apps can be used by entering ./app1 in the command line
	$(CC) app1.o Lab1.o -o app1

app2: app2.o
	$(CC) app2.o Lab2.o -o app2

app3: app3.o
	$(CC) app3.o Lab3.o -o app3

app4: app4.o
	$(CC) app4.o Lab4.o Lab1.o -o app4

app5: app5.o
	$(CC) app5.o Lab5.o Lab4.o Lab1.o -o app5

app6: app6.o
	$(CC) app6.o Lab6.o -o app6
	
#_____________________________________________________________________________________________

app1.o: app1.cpp Lab1.o
	$(CC) $(CFLAGS) app1.cpp

app2.o: app2.cpp Lab2.o
	$(CC) $(CFLAGS) app2.cpp

app3.o: app3.cpp Lab3.o
	$(CC) $(CFLAGS) app3.cpp

app4.o: app4.cpp Lab4.o Lab1.o
	$(CC) $(CFLAGS) app4.cpp

app5.o: app5.cpp Lab5.o Lab4.o Lab1.o
	$(CC) $(CFLAGS) app5.cpp

app6.o: app6.cpp Lab6.o
	$(CC) $(CFLAGS) app6.cpp

#_____________________________________________________________________________________________


Lab1.o: Lab1.cpp Lab1.h
	$(CC) $(CFLAGS) Lab1.cpp

Lab2.o: Lab2.cpp Lab1.h
	$(CC) $(CFLAGS) Lab2.cpp

Lab3.o: Lab3.cpp Lab3.h
	$(CC) $(CFLAGS) Lab3.cpp

Lab4.o: Lab1.o Lab4.cpp Lab4.h
	$(CC) $(CFLAGS) Lab4.cpp

Lab5.o: Lab1.o Lab4.o Lab5.cpp Lab5.h
	$(CC) $(CFLAGS) Lab5.cpp

Lab6.o: Lab6.cpp Lab6.h
	$(CC) $(CFLAGS) Lab6.cpp


clean:
	rm -rf *o
	find . -maxdepth 1 -type f -executable -exec rm {} +



