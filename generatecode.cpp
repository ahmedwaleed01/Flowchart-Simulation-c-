#include "generatecode.h"
#include<fstream>
generatecode::generatecode(ApplicationManager* pAppManager):Action(pAppManager)
{
	pO = pAppManager->GetOutput();
}

void generatecode::ReadActionParameters()
{
	pO->PrintMessage("Generate code function ");
	ofstream Of("code.cpp", ios::out);
	for (int i = 0; i < pManager->getrealstat(); i++)
	{
		
		Statement** d = pManager->getstatement();
		select = d[i];
		select->GenerateCode(Of);
	}
}
	


void generatecode::Execute()
{
	ReadActionParameters();
}
