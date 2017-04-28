###############################################################
# Program:
#     Week 02, STACK
#     Brother JonesL, CS235
# Author:
#     David Donovan, David Perez Jeffry Simpson
# Summary:
#     Create a class encapsulating the notion of a stack
# Time:
#     Pair programming 1 hour
#	  Jeffry - 1.5 hour
#	  David D - 
#     David P -
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h week02.o infix.o 
	g++ -o a.out week02.o infix.o 
	tar -cf week02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week02.o       : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
week02.o: stack.h infix.h week02.cpp
	g++ -c week02.cpp

infix.o: stack.h infix.h infix.cpp
	g++ -c infix.cpp

clean:
	rm *.o a.out
