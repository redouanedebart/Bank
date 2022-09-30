cmake_minimum_required(VERSION 3.23)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank src/main.cpp include/Cashier.h include/Client.h include/WaitingQueue.h include/Bank.h include/DES.h include/Event.h include/Departure.h include/Arrival.h src/Cashier.cpp src/WaitingQueue.cpp src/Bank.cpp src/Event.cpp src/DES.cpp src/Arrival.cpp src/Client.cpp src/Departure.cpp)
