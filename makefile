#makefile
CC = g++
CFLAGS = -I ./include
BANK = src/DES.o src/Bank.o src/Event.o src/Arrival.o src/Cashier.o src/Client.o src/Departure.o  src/WaitingQueue.o src/main.o
all: $(BANK)
	$(CC) -o bank $(BANK) $(CFLAGS)
clean:
	rm -f bank src/*.o

DES.o: include/DES.h include/Event.h
Event.o: include/Event.h
Arrival.o: include/Arrival.h include/Event.h
Cashier.o: include/Cashier.h include/Client.h include/Bank.h
Client.o: include/Client.h
Departure.o: include/Departure.h include/Event.h
WaitingQueue.o: include/WaitingQueue.h include/Bank.h include/Client.h
Bank.o:include/Bank.h include/DES.h include/WaitingQueue.h include/Cashier.h
main.o: include/Bank.h