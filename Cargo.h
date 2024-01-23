#pragma once
#include "Time.h"

class Cargo
{
	Time PreparationTime;
	int LoadUnloadTime;
	int DeliveryDistance;
	int Cost;
	Time CDT;
	int TID; 
	Time WT; 
	//Instead of using polymorphism , and since the only difference between cargos is the cargo type 
	//we decided to add data member to indicate the type
	char CargoType;
	int ID;
public:
	//     CONSTRUCTORS



	Cargo(Time Prep, int Load, int DD, int C,int id,char CT);

	Cargo();

	//-----------------------------------------------------//
	


	//      GETTERS
	


	// fuction to return cargo type



	char GetCT();  

	// fuction to return cargo ID



	int GetID();

	// fuction to return cargo cost



	int GetCost();

	// fuction to return cargo DeliveryDistance


	int GetDeliveryDistance();

	// fuction to return cargo PreparationTime


	Time GetPreparationTime();

	// fuction to return cargo LoadUnloadTime
	int GetLoadUnloadTime();

	//-----------------------------------------------------//



	//     SETTERS
	


	// fuction to set cargo cost


	void SetCost(int C);


	// fuction to set CargoType


	
	void SetCargoType(char CT);

	int CalcPrio();

	void SetCDT(Time Current);
	Time GetCDT();

	void SetTID(int tid);
	int GetTID();

	void SetWT(Time Wait);

	Time GetWT();

};

