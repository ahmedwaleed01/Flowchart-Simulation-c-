#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Actions\readaction.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\readt.h"
#include<iostream>
#include<stdlib.h>

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "Action.h"
class ApplicationManager;
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
readaction::readaction(ApplicationManager* pAppManager) :Action(pAppManager)
{
	pManager = pAppManager;
}

void readaction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMessage("read Assignment Statement: Click to add the statement");
	string g, m = "";
	g = pIn->getstringpure(canbedone1, pOut);
	rhs = g;

	pIn->updatesize(g, width, hei);
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void readaction::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x ;
	Corner.y = Position.y ;
	readt* pAssign = new readt(pManager, Corner, "Read ", rhs, (2*UI.defualt_width + width), ((UI.defualt_height+hei)));
	if (!pAssign->intersection(pManager) && canbedone1 == true)
	{
		pManager->AddStatement(pAssign);
	}
	else
	{
		pOut->PrintMessage("error");
	}
}

