#include "startaction.h"


startaction::startaction(ApplicationManager* pAppManager) :Action(pAppManager)
{
	pManager = pAppManager;
}

void startaction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMessage("Start Statement: Click to add the statement");


	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void startaction::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block

	Point Corner;
	Corner.x = Position.x + UI.defualt_width / 9;
	Corner.y = Position.y - UI.defualt_height / 2;

	ptr = new start(pManager, Corner, UI.defualt_width, UI.defualt_height);
	ptr->intersection(pManager);
	if (!ptr->intersection(pManager))

		pManager->AddStatement(ptr);
	else
		pOut->PrintMessage("error");

}