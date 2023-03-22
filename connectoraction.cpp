#include<iostream>
using namespace std;
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\Actions\connectoraction.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\start.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Endd.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\conditionalstat.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\SmplAssign.h"
class ApplicationManager;
connectoraction::connectoraction(ApplicationManager* pAppManager):Action (pAppManager)
{
	pManager = pAppManager;
	corner1 = NULL;
	corner2 = NULL;
	pIn = NULL;
	pOut = NULL;
}
void connectoraction::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pOut->PrintMessage("connector Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position1);

	pIn->GetPointClicked(Position2);
	pOut->ClearStatusBar();
}

void connectoraction::Execute()
{
	ReadActionParameters(); 
	corner1=pIn->intersectselect(pManager, Position1);
	corner2 = pIn->intersectselect(pManager, Position2);
	
	Connector* c = new Connector(pManager,corner1, corner2,Position1,Position2,pIn);
	if (corner1 != NULL && corner2 != NULL)
		pManager->Addconnector(c);
	else
		pOut->PrintMessage("something is wrong");
	
}