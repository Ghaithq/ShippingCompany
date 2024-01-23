#pragma once

#include "Truck.h"
#include "PriorityQueue.h"


//Special truck derived class
class SpecialTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpDuration;
public:
	//Constructor
	SpecialTruck();
	SpecialTruck(int DI);
	//Set static members
	static void SetStaticMembers(int TC, int S, int CUD);
	void SetDeliveryInterval();
	static int GetTruckCapacity();
	int GetSpeed();
	static int GetCheckUpDuration();
	void SetEndOfCheckUp(Time EOCU);
	bool IsFull();
	void SetCargosCDT();

};

