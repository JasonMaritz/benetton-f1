OBJECTS := Container.o TransportMode.o Truck.o Ship ChartedPlane.o HighPriority.o     main.o
#  $(OBJECTS)
main: $(OBJECTS)
	g++ -g Container/*.cpp Shipping/HighPriority.cpp Shipping/TransportMode.cpp Shipping/ChartedPlane.cpp Shipping/Ship.cpp Shipping/Truck.cpp main.cpp  -o main

main.o: main.cpp
	g++ -c -g main.cpp 

Container.o: Container/*.cpp Container/*.h
	g++ -g Container/*.cpp 

TransportMode.o: Shipping/TransportMode.h Shipping/TransportMode.cpp
	g++ -g Shipping/TransportMode.cpp

Truck.o: Shipping/Truck.h Shipping/Truck.cpp
	g++ -g Shipping/Truck.cpp


Ship.o: Shipping/Ship.h Shipping/Ship.cpp
	g++ -g Shipping/Ship.cpp

ChartedPlane.o: Shipping/ChartedPlane.h Shipping/ChartedPlane.cpp
	g++ -g Shipping/ChartedPlane.cpp

HighPriority.o: Shipping/HighPriority.h Shipping/HighPriority.cpp
	g++ -g Shipping/HighPriority.cpp
	
run:
	./main
