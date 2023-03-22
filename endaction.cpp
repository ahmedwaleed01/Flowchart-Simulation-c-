#include "endaction.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"


#include <sstream>
class Action;
endaction::endaction(ApplicationManager* pAppManager):Action(pAppManager)
{
	pManager = pAppManager;
}

void endaction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMessage("End Statement: Click to add the statement");


	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void endaction::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	
	Point Corner;
	Corner.x = Position.x + UI.defualt_width / 9;
	Corner.y = Position.y - UI.defualt_height / 2;
	ptr = new Endd(pManager, Corner, UI.defualt_width, UI.defualt_height);
	ptr->intersection(pManager);
	if (!ptr->intersection(pManager))
	
		pManager->AddStatement(ptr);
	else
		pOut->PrintMessage("error");

	
}
