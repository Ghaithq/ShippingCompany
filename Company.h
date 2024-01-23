#pragma once
#include "Event.h"
#include "CancelEvent.h"
#include "PreparationEvent.h"
#include "PromoteEvent.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Cargo.h"
#include "Truck.h"
#include "NormalTruck.h"
#include "SpecialTruck.h"
#include "VIPTruck.h"
#include"UI.h"
#include <fstream>
#include<string>

class Company
{
	int AutoPromotion;
	int MaxW;
	int NumberOfAutoPromotions;
	Queue < Event* > EventsList;
	Queue<Cargo*> WaitingSpecialCargos;
	PriorityQueue<Cargo*> WaitingVIPCargos;
	LinkedList<Cargo*> WaitingNormalCargos;
	PriorityQueue<Truck*> MovingTrucks;
	Queue<Cargo*> DeliveredCargos;
	Queue<NormalTruck*> EmptyNormalTrucks;
	Queue<SpecialTruck*> EmptySpecialTrucks;
	Queue<VIPTruck*> EmptyVIPTrucks;
	Queue<Truck*> LoadingTrucks;
	Queue<NormalTruck*> NormalCheckUpTrucks;
	Queue<SpecialTruck*> SpecialCheckUpTrucks;
	Queue<VIPTruck*> VIPCheckUpTrucks;
	Truck* NormalLoadingTruck;
	Truck* SpecialLoadingTruck;
	Truck* VIPLoadingTruck;

public:
	//The Funcion Responsible for The Simulation
	void Simulate(int Type, string InputFile);

	//      CONSTRUCTORS
	
	Company();

	//-----------------------------------------------------//
	
	//      ENQUEUING/INSERTING FUNCTIONS
	
	// function to enqueue a cargo into Waiting Special Queue
	
	void enqueueWSC(Cargo* SC);

	// function to enqueue a cargo into Waiting VIP Queue

	void enqueueWVC(Cargo* VC,int Priority);

	// function to insert a cargo into Waiting Normal List

	void insertWNC(Cargo* NC);

	// function to insert a cargo in the beginning of the Waiting Normal List

	void insertFirstWNC(Cargo* NC);

	// function to enqueue a cargo into Events Queue

	void AddEvent(Event* E);

	// function to enqueue a cargo into Delivered queue

	void EnqueueDC(Cargo* SC);

	// function to enqueue moving truck int moving trucks queue
	
	void EnqueueMT(Truck* MT);


	//-----------------------------------------------------//


	//      DEQUEUEING/REMOVING FUNCTIONS


	// function to remove a cargo from Waiting Normal List according to ID

	Cargo* RemoveWNC(int id);
		
	// function to Dequeue a cargo from Waiting VIP Cargos

	bool DequeueWVC(Cargo*& VC);

	// function to Dequeue a cargo from Waiting Special Cargos

	bool DequeueWSC(Cargo*& SC);

	// function to Dequeue an event from Events Queue

	bool DequeueEvent(Event*& E);

	// function to Remove First cargo from Waiting Normal Cargos List

	bool RemoveFirstWNC(Cargo*& NC);

	//-----------------------------------------------------//


	//      PRINTING OF QUEUES/LISTS FUNCTIONS  BY CALLING  PRINT FUNCTIONG IN QUEUES


	// function to print Waiting Normal Cargos List

	void PrintWNC();

	// function to print Waiting Speical Cargos Queue

	void PrintWSC();

	// function to print Waiting VIP Cargos

	void PrintWVC();

	// function to print Delivered Cargos Queue

	void PrintDC();

	//function to print empty normal trucks

	void PrintENT();

	//function to print empty special trucks

	void PrintEST();

	//function to print empty VIP trucks

	void PrintEVT();

	//function to print moving trucks

	void PrintMovingTrucks();

	//function to print normal checkup trucks

	void PrintNCT();

	//function to print special checkup trucks

	void PrintSCT();

	//function to print VIP checkup trucks

	void PrintVCT();

	//-----------------------------------------------------//


	//      LOADING FUNCTION


	void LoadFile(string Input);


	//-----------------------------------------------------//


	//      OTHER FUNCTIONS

	//function to return count of all Waiting Cargos

	int WaitingNormalCount();
	int WaitingSpecialCount();
	int WaitingVIPCount();
	
	//function to get the number of loading trucks 

	int GetLoadingTruckCount();

	//function to get number of empty trucks 

	int GetEmptyTruckCount();

	//function to get number of moving cargos

	int GetMovingCargoCount();

	//function to get number of incheckup trucks

	int GetCheckupCount();

	//function to return count of all Delivered Cargos

	int DeliveredCount();

	//function to get the waiting index

	int GetWaitingIndex(int ID);

	//function to Get AutoPromotion

	int GetAutoPromotion();

	//function to Set AutoPromotion

	void SetAutoPromotion(int AP);

	//function to Autopromote

	void AutoPromote(Time CurrentTime);

	//function to load cargos

	void LoadCargos(int& NLT, int& SLT, int& VLT,Time CurrentTime);
	
	//function to Deliver cargos

	void DeliverCargos(Time Current);

	// function to move a truck from moving to avail

	void MoveToAvail();

	// function to move a truck from moving to checkup

	void MoveToCheckUp(Time Current);

	//function to move from checkup to avail

	void MoveCheckUpToAvail(Time Current);

	//fuction to set the normal loading truck

	void SetNormalLoadingTruck(Truck* Nptr);
	
	//fuction to set the special loading truck

	void SetSpecialLoadingTruck(Truck* Sptr);

	//fuction to set the VIP loading truck

	void SetVIPLoadingTruck(Truck* Vptr);

	//fuction to get the normal loading truck

	Truck* GetNormalLoadingTruck();

	//function to get the special loading truck

	Truck* GetSpecialLoadingTruck();

	//fuction to get the VIP loading truck

	Truck* GetVIPLoadingTruck();

	// fuction to handle the maxw rule

	void HandleMaxW(int& NLT, int& SLT, Time CurrentTime);

	//funtion to execute events

	void ExecuteEvents(Event*& CurrentEvent,Time CurrentTime);

	//function to increment the counters in the simulation function

	void AdvanceSimTime(int& hour, int& day, int& NLT, int& SLT, int& VLT);

	//function to generate the output file

	void GenerateOutputFile(Time EndSimTime);

	//function to check that all cargos is delivered 

	bool AllIsDelivered();

	//function to decrement returning hours

	void DecrementReturningHours();

	//function to handle the delivery failure

	void DeliveryFailure(Truck* MT);
};

