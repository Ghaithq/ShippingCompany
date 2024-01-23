#pragma once
#include"Company.h"
#include<string.h>

//Class Responsible for The Interface
class UI
{
public:
 
	//     Function Display that Print The Cargos Lists data according to the desired format
	void Display(Company & C,int Type,Time CurrentTime);
	void DisplayEndText(Company& C, int Type, Time EndSimTime);
};

