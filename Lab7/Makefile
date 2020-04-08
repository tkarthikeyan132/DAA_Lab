#declare variables 
CC = g++

CFLAGS = -c -w

all: app1 app2 app3 app4


app1: app1.o
	$(CC) app1.o BASIC.o -o app1
	
app2: app2.o
	$(CC) app2.o LINALG.o -o app2
	
app3: app3.o
	$(CC) app3.o SCIENTIFIC.o BASIC.o -o app3
	
app4: app4.o
	$(CC) app4.o SORT_SEARCH.o -o app4

#---------------------------------------------------------------

app1.o: app1.cpp BASIC.o
	$(CC) $(CFLAGS) app1.cpp
	
app2.o: app2.cpp LINALG.o
	$(CC) $(CFLAGS) app2.cpp 
	
app3.o: app3.cpp SCIENTIFIC.o BASIC.o
	$(CC) $(CFLAGS) app3.cpp
	
app4.o: app4.cpp SORT_SEARCH.o
	$(CC) $(CFLAGS) app4.cpp

#----------------------------------------------------------------

BASIC.o: BASIC.cpp BASIC.h
	$(CC) $(CFLAGS) BASIC.cpp
	
LINALG.o: LINALG.cpp LINALG.h
	$(CC) $(CFLAGS) LINALG.cpp
	
SCIENTIFIC.o: BASIC.o SCIENTIFIC.cpp SCIENTIFIC.h 
	$(CC) $(CFLAGS) SCIENTIFIC.cpp

SORT_SEARCH.o: SORT_SEARCH.cpp SORT_SEARCH.h
	$(CC) $(CFLAGS) SORT_SEARCH.cpp
	
#--------------------------------------------------------------

clean:
	rm -rf *o
	find . -maxdepth 1 -type f -executable -exec rm {} +
