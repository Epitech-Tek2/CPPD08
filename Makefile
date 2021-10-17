##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPD17-clement.muth
## File description:
## Makefile
##

testobj =	tests/ex00/testEx00Operator.cpp \
			tests/ex00/testEx00GetterSetter.cpp \
			tests/ex00/testEx00MainPdf.cpp

fileobj =	ex00/*.cpp

tests_run:
	g++ $(fileobj) $(testobj) -o unit_tests --coverage -lcriterion
	- ./unit_tests


tests_run1:
	g++ ex01/*.cpp tests/ex01/*.cpp -o unit_tests --coverage -lcriterion
	- ./unit_tests

tests_run2:
	g++ ex02/*.cpp tests/ex02/*.cpp -o unit_tests --coverage -lcriterion
	- ./unit_tests