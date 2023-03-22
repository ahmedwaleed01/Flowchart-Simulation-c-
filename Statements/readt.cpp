#include "readt.h"
#include<iostream>
#include<fstream>
#include <sstream>
readt::readt(ApplicationManager* a, Point g, string go, string op, int width, int height) :Statement(a, in, out, width, height, g)
{
	A = a;
	gauche = go;
	UpdateStatementText();
	aumilieu = op;
	UpdateStatementText();
	this->width = width;
	this->height = height;
	pOut = out;
	pin = in;
}
void readt::Save(ofstream& Os)
{
	Os << "Type conditional" << "id= " << ID << " " << left.x << " " << left.y << " " << gauche << " " << aumilieu << endl;
	Os << com << endl;
	Os.close();
}
bool readt::getcheck()
{
	return check;
}


void readt::UpdateStatementText()
{
	if (gauche != "Read ")	//No left handside ==>statement have no valid text yet
		Text = "error!";
	else if (aumilieu == "=")
	{
		Text = "error!";
	}

	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << gauche << aumilieu;
		Text = T.str();

	}
}
void readt::Draw(Output* pOut) const
{
	pOut->ReadOrPrint(left, width, height, Selected, Text);


}
Point& readt::getpOutval()
{
	pOut.x = this->getleft().x +   width;
	pOut.y = this->getleft().y +  1.5* height;

	return pOut;
}
Point& readt::getpintval()
{

	pin.x = left.x;
	pin.y = left.y + height+UI.defualt_height;

	return pin;
}

void readt::Edit() {
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function ");
	gauche = pri->GetString(pro);
	aumilieu = pri->GetString(pro);

	UpdateStatementText();

}

void readt::Simulate()
{

}
void readt::GenerateCode(ofstream& OutFile)
{
	OutFile << "cout" << ">>" << aumilieu << ">>" << "endl" << ";" << endl;

}
void readt::PrintInfo(Output* pOut) {
	pOut->PrintMessage(com);

}

void readt::Move(Point p)
{
	left = (p);
	Draw(pro);


}