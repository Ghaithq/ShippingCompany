#include "SpecialTruck.h"
#include "Queue.h"

int SpecialTruck::TruckCapacity = 0;
int SpecialTruck::Speed = 0;
int SpecialTruck::CheckUpDuration = 0;

SpecialTruck::SpecialTruck(int DI) :Truck(DI)
{

}

SpecialTruck::SpecialTruck()
{

}

void SpecialTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

void SpecialTruck::SetDeliveryInterval()
{
	int LoadHours = 0;
	int FurthestDis;
	Queue<Cargo*> CargosTemp;
	Cargo* CTemp;
	while (CargosQueue.Dequeue(CTemp))
	{
		LoadHours += CTemp->GetLoadUnloadTime();
		CargosTemp.Enqueue(CTemp);
	}
	if (CTemp)
		FurthestDis = CTemp->GetDeliveryDistance();
	while (CargosTemp.Dequeue(CTemp))
	{
		CargosQueue.enqueue(CTemp, CTemp->CalcPrio());
	}
	DeliveryInterval = 2.0 * FurthestDis / Speed + LoadHours;
	TruckActiveTime += FurthestDis / Speed + 2 * LoadHours;
	ReturningHours = FurthestDis / Speed ; 
}

int SpecialTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int SpecialTruck::GetSpeed()
{
	return Speed;
}
int SpecialTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void SpecialTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}

bool SpecialTruck::IsFull()
{
	return (CargosQueue.GetCount() == TruckCapacity);
}

void SpecialTruck::SetCargosCDT()
{
	Queue<Cargo*> TempQueue;
	Cargo* Temp;
	int SumOfUnloadTimes = 0;
	int CDTHrs = 0;
	while (CargosQueue.Dequeue(Temp))
	{
		TempQueue.Enqueue(Temp);
		SumOfUnloadTimes += Temp->GetLoadUnloadTime();
		CDTHrs = MovingTime.day * 24 + MovingTime.hour + Temp->GetDeliveryDistance() / Speed + SumOfUnloadTimes;
		Temp->SetCDT(Time(CDTHrs % 24, CDTHrs / 24));
	}
	while (TempQueue.Dequeue(Temp))
	{
		CargosQueue.enqueue(Temp, Temp->CalcPrio());
	}
}