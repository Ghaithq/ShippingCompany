#pragma once
#include "Cargo.h"
#include "PriorityQueue.h"

//Truck Base Class (Pure Virtual)
class Truck
{
protected:
	int DeliveryInterval;
	PriorityQueue <Cargo*> CargosQueue;
	Time MovingTime;
	int TotalJourneys;
	static int J;
	int EndOfCheckUp;
	bool EmergencyFlag;
	int TID;
	static int TruckCount;
	int TruckActiveTime;
	int TDC;
	int ReturningHours;
	bool DeliveryFailed;

public: 
	// Constructors 
	Truck(int DI);
	Truck();
	//Load cargos into the truck
	void LoadCargo(Cargo* C);
	//Set the truck's moving time
	void SetMovingTime(Time T);
	//Get the truck's initial moving time
	Time GetMovingTime();
	//Peek at the truck's queue of cargos
	bool PeekCargosQueue(Cargo*& C);
	//dequeue the trucks queue of cargos
	bool DequeueCargo(Cargo*& C);
	//A virtual function to get the truck's speed
	virtual int GetSpeed() = 0;
	//A virtual function to set the truck's delivery interval
	virtual void SetDeliveryInterval() = 0;
	//Get the truck's delivery interval
	int GetDeliveryInterval();
	//Calcualte the truck's priority
	int CalcPrio();
	//Set the truck's total journeys made
	void SetTotalJourneys(int TJ);
	//Get the truck's total journeys
	int GetTotalJourneys();
	//Set the number of journeys needed before chekup
	static void SetJ(int j);
	//Set the number of journeys needed before chekup
	static int GetJ();
	//Check whether the truck is empty 
	bool IsEmpty();
	//A virtual function to set the time at which the checkup ends
	virtual void SetEndOfCheckUp(Time EOCU) = 0;
	int GetEndOfCheckUp();
	//A virtual function to check if the truck is full
	virtual bool IsFull() = 0;
	//Set the emergency flag of the truck
	void SetEFlag(bool F);
	//Get the emergency flag of the truck
	bool GetEFlag();
	//Get the truck's ID
	int GetTID();
	//Print the cargos of the moving truck
	void PrintTruckCargos();
	//Print the truck's ID
	void PrintID();
	//Get the count of the cargos of the moving truck
	int GetCargoCount();
	//Set the Waiting time of all cargos
	void SetCWT();
	//Get the active time of the truck 
	int GetActiveTime();
	//Set the total delivered cargos of the truck
	void SetTDC(int tdc);
	//Get the total cargos delivered by the truck
	int GetTDC();
	//A virtual function to set the return hours of the truck after it has finished delivering
	virtual void SetReturnH(int h);
	//Get the return hours of the truck 
	virtual int GetReturnH();
	//A virtual function to set the total cargos delivered by the truck
	virtual void SetCargosCDT()=0;
	//return whether the truck has failed to deliver 
	bool GetDeliveryFailed();
	//Set to true if it has failed to deliver 
	void SetDeliveryFailed(bool b);
};