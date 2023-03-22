#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Actions\writeaction.h"

#include<iostream>
#include<stdlib.h>

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "Action.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
writeaction::writeaction(ApplicationManager* pAppManager):Action(pAppManager)
{
	pManager = pAppManager;
}

void writeaction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMessage("write Assignment Statement: Click to add the statement");
	string g, m = "";
	g = pIn->getstringpure(canbedone1, pOut);
	rhs = g;
	
	pIn->updatesize(g, width, hei);
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void writeaction::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - (UI.defualt_width + width) ;
	Corner.y = Position.y - (4*hei) ;
	write* pAssign = new write(pManager, Corner, "Write ", rhs, (UI.defualt_width +width), (4*hei));
	if (!pAssign->intersection(pManager) && canbedone1 == true)
	{
		pManager->AddStatement(pAssign);
	}
	else
	{
		pOut->PrintMessage("error");
	}
}

