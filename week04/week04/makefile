###############################################################
# Program:
#     Week 04, DEQUE
#     Brother JonesL, CS235
# Author:
#     Jeffry Simpson, David Perez
# Summary:
#     Implements a deque and is used to solve now serving problem
# Time:
#     David Perez - 4 hours
#     Jeffry Simpson - 
# Difficulties:
#     David Perez -  Finding a way to reallocate the dynamic 
#                    array to pass test 3 in the test bed.
#     Jeffry Simpson - 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h week04.o nowServing.o
	g++ -o a.out week04.o nowServing.o
	tar -cf week04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week04.o       : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
week04.o: deque.h week04.cpp
	g++ -c week04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp
