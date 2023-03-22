#include "..\ApplicationManager.h"
#include"moveaction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "Action.h"
moveaction::moveaction(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void moveaction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pOut->PrintMessage("move function ");
	pIn->GetPointClicked(firstp);
	pIn->GetPointClicked(lastp);
	select = pIn->intersectselect(pManager, firstp);
	select->Move(lastp);
}

void moveaction::Execute()
{
	ReadActionParameters();
}
