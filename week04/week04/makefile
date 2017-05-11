###############################################################
# Program:
#     Week 04, DEQUE
#     Brother XXXXX, CS235
# Author:
#     <your name here>
# Summary:
#     <put a description here>
# Time:
#    Pair programming - 1.0
#	  Jeffry Simpson - 4.0
#    David Perez    -
#
# Difficulties:
#    David P -
#
#
#   Jeffry -
#
#
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
	g++ -std=c++11 -c week04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -std=c++11 -c nowServing.cpp
