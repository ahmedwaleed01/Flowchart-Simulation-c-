#pragma once
#include "Action.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\start.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\conditionalstat.h"
#include<string>
class generatecode:public Action
{
private:
	Output* pO;
	Statement* select;
	Statement* sec;
public:
	generatecode(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	void Execute();
};

