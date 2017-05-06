###############################################################
# Program:
#     Week 03, QUEUE
#     Brother JonesL, CS235
# Author:
#     David Donovan, David Perez Jeffry Simpson
# Summary:
#     Create a class encapsulating the notion of a stack
# Time:
#    Pair programming - 2.5
#	  Jeffry Simpson - 3.5
#	  David Donavan  - 
#    David Perez    - 5
#
# Difficulties:
#    David P - Fixing the push function to allocate capacity after the size
#              is full. The problem rooted in the copy constructor.
#
#   Jeffry - Getting Stock class to work correctly including overloaded and
#            friend functions
#
#   David D -
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h week03.o dollars.o stock.o
	g++ -o a.out week03.o dollars.o stock.o
	tar -cf week03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      week03.o       : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
week03.o: queue.h week03.cpp
	g++ -std=c++11 -c week03.cpp

dollars.o: dollars.h dollars.cpp
	g++ -std=c++11 -c dollars.cpp

stock.o: stock.h stock.cpp queue.h
	g++ -std=c++11 -c stock.cpp


##############################################################
# Clean up
##############################################################
clean:
	rm *.o a.out *~

