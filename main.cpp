#include<iostream>
#include "Company.h"
#include "PreparationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"
#include"UI.h"
#include<fstream>

using namespace std;

int main()
{
	UI Interface;
	Company C;
	int Type;
	//    Type 1---> Interactive Mode 
	//    Type 2---> Step-By-STep Mode
	//    Type 3---> SilentMode

	cin >> Type;
	string FileName;
	cin >> FileName;
	cin.get();
	C.Simulate(Type, FileName+".txt");
	
}