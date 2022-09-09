cmake_minimum_required(VERSION 3.23)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp Cashier.h Client.h WaitingQueue.h Bank.h DES.h Event.h Departure.h Arrival.h Cashier.cpp WaitingQueue.cpp Bank.cpp Event.cpp DES.cpp Arrival.cpp Client.cpp Departure.cpp)
