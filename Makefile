testbst: intbst.o testbst.o
	g++ intbst.o testbst.o -o testbst
intbst: intbst.cpp intbst.h
	g++ -c intbst.cpp
clean:
	rm *.o testbst

