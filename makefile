#makefile
CC = g++
CFLAGS =
BANK = DES.o Bank.o Event.o Arrival.o Cashier.o Client.o Departure.o  WaitingQueue.o main.o
all: $(BANK)
	$(CC) -o bank $(BANK) $(CFLAGS)
clean:
	rm -f bank *.o

DES.o: DES.h Event.h
Event.o: Event.h
Arrival.o: Arrival.h Event.h
Cashier.o: Cashier.h Client.h Bank.h
Client.o: Client.h
Departure.o: Departure.h Event.h
WaitingQueue.o: WaitingQueue.h Bank.h Client.h
Bank.o:Bank.h DES.h WaitingQueue.h Cashier.h
main.o: Bank.h