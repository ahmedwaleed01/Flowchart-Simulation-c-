#include "AddSmplAssign.h"

#include<iostream>
#include<stdlib.h>
using namespace std;

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSmplAssign::AddSmplAssign(ApplicationManager *pAppManager):Action(pAppManager)
{
	pManager = pAppManager;
}

void AddSmplAssign::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");
	string g, m="";
	CHAR R;
	g = pIn->getstringpure(canbedone1,pOut);
	lhs = g;
		
	

		double t;
		
		if (canbedone1) {
			t = pIn->GetValue(m, pOut);
			rhs = t;
			
		}
		string text;
		text = lhs + m;
		pIn->updatesize(text, width, hei);
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();		
}

void AddSmplAssign::Execute()
{
 	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - (UI.defualt_width+width)/ 9;
	Corner.y = Position.y-(UI.defualt_height+hei)/1.5 ;

	SmplAssign* pAssign = new SmplAssign(pManager, Corner, UI.defualt_width+width, UI.defualt_height-hei, lhs, rhs);
	if (!pAssign->intersection(pManager) && canbedone1==true )
	{
		pManager->AddStatement(pAssign);
	}
	else
	{
		pOut->PrintMessage("error");
	}
}

