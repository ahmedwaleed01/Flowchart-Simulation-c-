#pragma once
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "Action.h"
#include<string>
class moveaction:public Action
{
private:
	Point firstp;
	Point lastp;
	Input* pIn;
	Output* pOut;
	Statement* select;
public:
	moveaction(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	void Execute();
};

