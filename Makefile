CC=g++
CFLAGS=-I/usr/local/include -L/usr/local/lib
CVERSION=-std=c++14

LIBS= -lwt -lwthttp -lboost_system


all: main

default: main

main: main.o Address.o Name.o Phone.o Person.o Generate.o MyResource.o log.o
	$(CC) $(CVERSION) -o app main.o Address.o Name.o Phone.o Person.o Generate.o MyResource.o log.o $(CFLAGS) $(LIBS)

main.o: main.cpp
	$(CC) $(CVERSION) -c main.cpp $(CFLAGS) $(LIBS)

Address.o: Address.cpp Address.h
	$(CC) $(CVERSION) -c Address.cpp $(CFLAGS) $(LIBS)

Name.o: Name.cpp Name.h
	$(CC) $(CVERSION) -c Name.cpp $(CFLAGS) $(LIBS)

Phone.o: Phone.cpp Phone.h
	$(CC) $(CVERSION) -c Phone.cpp $(CFLAGS) $(LIBS)

Person.o: Person.cpp Person.h
	$(CC) $(CVERSION) -c Person.cpp $(CFLAGS) $(LIBS)

MyResource.o: MyResource.cpp MyResource.h
	$(CC) $(CVERSION) -c MyResource.cpp $(CFLAGS) $(LIBS)

Generate.o: Generate.cpp Generate.h
	$(CC) $(CVERSION) -c Generate.cpp $(CFLAGS) $(LIBS)

log.o: log.cpp log.h
	$(CC) $(CVERSION) -c log.cpp $(CFLAGS) $(LIBS)

clean: 
	rm -f main.o Address.o Name.o Phone.o Person.o Generate.o MyResource.o log.o app

run: main.o  Address.o Name.o Phone.o Person.o Generate.o MyResource.o log.o
	./app --docroot ./ --http-address 127.0.0.1 --http-port 8080