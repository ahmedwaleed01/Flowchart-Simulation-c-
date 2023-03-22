#pragma once
#include"Action.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Endd.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include<string>
class Action;
class endaction:public Action
{
private:
	string text;
	Input* pIn;
	Endd* ptr;
	Output* pOut;
	int width;

	int hei;
	Point Position;	//Position where the user clicks to add the stat.
public:
	endaction(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	 void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	 void Execute();
};

