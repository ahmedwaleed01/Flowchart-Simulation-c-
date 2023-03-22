#pragma once
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Actions\Action.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\conditionalstat.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Statement.h"
class ApplicationManager;
class connectoraction:public Action
{
private:
	Input* pIn;	Output* pOut;
	
	Point Position1;
	Point Position2;
	Statement *corner1;
	Statement *corner2;
	//Position where the user clicks to add the stat.
public:
	connectoraction(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	 void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	void Execute();

};

