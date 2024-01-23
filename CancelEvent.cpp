#include "CancelEvent.h"
#include "Company.h"
#include <iostream>
using namespace std;

bool CancelEvent::Execute(Company& Comp)
{
	//removing the cargo from waiting normal by ID list if found
	bool Check = true;
	if (Comp.GetNormalLoadingTruck())
	{
		int Index = Comp.GetWaitingIndex(ID);
		int Cap;
		Truck* TempTruck;
		TempTruck = Comp.GetNormalLoadingTruck();

		if (dynamic_cast<NormalTruck*>(TempTruck))
			Cap = NormalTruck::GetTruckCapacity();
		if (dynamic_cast<VIPTruck*>(TempTruck))
			Cap = VIPTruck::GetTruckCapacity();
		Check = Cap - TempTruck->GetCargoCount() < Index;
	}
	if (Check)
	{
		Cargo* CargoToBeDeleted = Comp.RemoveWNC(ID);

		//checking whether it was found or not

		if (CargoToBeDeleted)
		{

			//deallocating the cargo
			delete CargoToBeDeleted;
			return true;
		}
		return false;
	}
}

void CancelEvent::SetParameters(int id)
{
	ID = id;
}