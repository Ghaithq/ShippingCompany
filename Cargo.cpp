#include "Cargo.h"


Cargo::Cargo(Time Prep, int Load, int DD, int C,int id,char CT)
{
	PreparationTime = Prep;
	LoadUnloadTime = Load;
	DeliveryDistance = DD;
	Cost = C;
	CargoType = CT;
	ID = id;
}

Cargo::Cargo()
{

}

char Cargo::GetCT()
{
	return CargoType;
}

int Cargo::GetID()
{
	return ID;
}

int Cargo::GetCost()
{
	return Cost;
}

Time Cargo::GetPreparationTime()
{
	return PreparationTime;
}

int Cargo::GetLoadUnloadTime()
{
	return LoadUnloadTime;
}

int Cargo::GetDeliveryDistance()
{
	return DeliveryDistance;
}

void Cargo::SetCargoType(char CT)
{
	CargoType = CT;
}

void Cargo::SetCost(int C)
{
	Cost = C;
}

int Cargo::CalcPrio()
{
	return (10000.0/DeliveryDistance);
}

void Cargo::SetCDT(Time Current)
{
	CDT = Current;
}

void Cargo::SetTID(int tid)
{
	TID = tid;
}													
void Cargo::SetWT(Time Wait)
{
	WT = Wait;
}

Time Cargo::GetCDT()
{
	return CDT;
}

Time Cargo::GetWT()
{
	return WT;
}

int Cargo::GetTID()
{
	return TID;
}
