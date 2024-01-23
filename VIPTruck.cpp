#include "VIPTruck.h"
#include "Queue.h"

int VIPTruck::TruckCapacity = 0;
int VIPTruck::Speed = 0;
int VIPTruck::CheckUpDuration = 0;
VIPTruck::VIPTruck()
{

}

VIPTruck::VIPTruck(int DI) :Truck(DI)
{

}


void VIPTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

void VIPTruck::SetDeliveryInterval()
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
	ReturningHours = FurthestDis / Speed;
}

int VIPTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int VIPTruck::GetSpeed()
{
	return Speed;
}
int VIPTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void VIPTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}

bool VIPTruck::IsFull()
{
	return (CargosQueue.GetCount() == TruckCapacity);
}
void VIPTruck::SetCargosCDT()
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