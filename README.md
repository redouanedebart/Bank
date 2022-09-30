# C++ Group Work
M2 IISC - CY Cergy Paris Université
## Table of content
1. Overview
2. How to use it
3. Documentation
4. V1 flaws and bugs
## Overview
This program aims at simulating a bank. More specifically, it is intended to give the user insights on the effectiveness
of the cashiers, the waiting time of clients, and so on. For more precise information, you can get the subject here :
[link to the subject.](https://depinfo.u-cergy.fr/~pl/docs/sujetBanque.pdf "sujet banque")
The program is written in C++, and a Makefile is provided.
## How to use it
Open the archive, and use the command `make` in the main directory. You can then use the command `./bank` to run the
program. At launch, the program will ask you the entry parameters for your simulation:
1. The expected duration of the simulation
2. The mean time between clients arrival
3. The number of cashiers present in the bank
4. For each cashier, his productivity, ie the average time it takes him to serve a client

*Note: the program doesn't yet manage careless inputs, so be careful.*

## Documentation
The source code is commented and doxygen documentation is available. If you have to
generate it again, a configuration file for doxygen is provided in the archive.
To generate the doxygen documentation, go to the directory where you have installed doxygen, where you can execute it by
typing `./doxygen` . Then write `export PATH=$PATH:.`. This will add the path of doxygen to the environment variable
path for this session. You can now go back to the source directory and just type `./doxygen configuration` 
in the terminal.

## V1 flaws and bugs
The program isn't working as well as I wanted, and does not return the results in a good way.
The issues I've met are segfaults, and also not changing a data structure soon enough, so it doesn't break
the whole thing. Given that some results are dependent, the output at the end of the simulation is often far from what
is expected.
Some testing has been made with the parameters 10, 2, 2, 2, 2.