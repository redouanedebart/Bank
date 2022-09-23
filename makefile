#makefile
CC = g++
CFLAGS = -I
BANK = Bank.o Arrival.o Cashier.o Client.o Departure.o DES.o Event.o WaitingQueue.o
bank: $(BANK)
	$(CC) -o bank $(BANK)
Bank.o:Bank.h DES.h WaitingQueue.h Cashier.h
Arrival.o: Arrival.h Event.h
Cashier.o: Cashier.h Client.h Bank.h
Client.o: Client.h
Departure.o: Departure.h Event.h
DES.o: DES.h Event.h
Event.o: Event.h
WaitingQueue.o: WaitingQueue.h Bank.h Client.h