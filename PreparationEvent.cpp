#include "PreparationEvent.h"
#include "Company.h"
#include "cmath"
bool PreparationEvent::Execute( Company& Comp) {
	//checking wich cargo type will be created

	if (CargoType == 'S')
	{
		//allocating a cargo 
		//assumed that Prep time is event time
		Cargo* SC = new Cargo(EventTime, LoadTime, Distance, Cost, ID, 'S');
		//enqueuing the cargo into the waiting special queue
		Comp.enqueueWSC(SC);
	}
	else if (CargoType == 'V')
	{
		//allocating a cargo 
		//assumed that Prep time is event time
		Cargo* V = new Cargo(EventTime, LoadTime, Distance, Cost, ID, 'V');
		int Priority = 10000*((Cost) / (Distance *(EventTime.day*24.0+ EventTime.hour)));
		//enqueuing the cargo into the waiting vip queue
		Comp.enqueueWVC(V, Priority);
	}
	else if (CargoType == 'N')
	{
		//allocating a cargo 
		//assumed that Prep time is event time
		Cargo* N = new Cargo(EventTime, LoadTime, Distance, Cost, ID, 'N');
		//enqueuing the cargo into the waiting normal list
		Comp.insertWNC(N);
	}
	return true;
}


void PreparationEvent::SetParameters(char CT, Time ET, int D, int LT, int C,int id)
{
	CargoType = CT;
	EventTime = ET;
	Distance = D;
	LoadTime = LT;
	Cost = C;
	ID = id;
}
