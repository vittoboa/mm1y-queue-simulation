simulation: mm1y.o utils.o Packet.o Simulation.o
	g++ mm1y.o utils.o Packet.o Simulation.o -o simulation

mm1y.o: mm1y.cpp
	g++ -c mm1y.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

Packet.o: Packet.cpp Packet.h
	g++ -c Packet.cpp

Simulation.o: Simulation.cpp Simulation.h
	g++ -c Simulation.cpp

clean:
	rm *.o simulation