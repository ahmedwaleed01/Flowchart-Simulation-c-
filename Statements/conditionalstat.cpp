#include "conditionalstat.h"
#include<iostream>
#include<fstream>
#include <sstream>
conditionalstat::conditionalstat(ApplicationManager*a,Point g,string go,string op,string fm,int width,int height):Statement(a,in,out, width,height,g)
{
	A = a;
	gauche = go;
	UpdateStatementText();
	aumilieu = op;
	UpdateStatementText();
	droit = fm;
	UpdateStatementText();
	this->width = width;
	this->height = height;
	pOut = left;
}
void conditionalstat::Save(ofstream& Os)
{
	Os << "Type conditional" << "id= " << ID << " " << left.x <<" " << left.y << " " << gauche << " " << aumilieu <<" " << droit<<endl;
	Os << com << endl;
	Os.close();
}
bool conditionalstat::getcheck()
{
	return check;
}


void conditionalstat::UpdateStatementText()
{
	if (gauche == "")	//No left handside ==>statement have no valid text yet
		Text = "error!";
	else if (aumilieu == "=")
	{
		Text = "error!";
	}
	else
		if (droit == "")	//No left handside ==>statement have no valid text yet
			Text = "error!";
		else
		{
			//Build the statement text: Left handside then equals then right handside
			ostringstream T;
			T << gauche << aumilieu << droit;
			Text = T.str();
			
		}
}
void conditionalstat::Draw(Output* pOut) const
{
	pOut->ConditionalStatement(left, width, height, Text, Selected);


}
Point& conditionalstat::getpOutval()
{


	return pOut;
}
Point& conditionalstat::getpintval()
{

	pin.x = left.x ;
	pin.y = left.y + height / 3.9;
	
	return pin;
}

void conditionalstat::Edit() {
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function ");
    gauche=	pri->GetString(pro);
    aumilieu= pri->GetString(pro);
    droit = pri->GetString(pro);

	UpdateStatementText();

}

void conditionalstat::Simulate()
{
	if (aumilieu == "<=") {
		if (gauche <= droit) {
			check = true;
		}
		else { check = false; }
	}
	else if (aumilieu == ">=") {
		if (gauche >= droit) {
			check = true;
		}
		else { check = false; }
	}
	else if (aumilieu == "<") {
		if (gauche < droit) {
			check = true;
		}
		else { check = false; }
	}
	else if (aumilieu == ">") {
		if (gauche > droit) {
			check = true;
		}
		else { check = false; }
	}
	else if (aumilieu == "==") {
		if (gauche == droit) {
			check = true;
		}
		else { check = false; }
	}
}
void conditionalstat::GenerateCode(ofstream& OutFile)
{ 
	OutFile << "if" << "(" << gauche+aumilieu+droit <<")" << endl;
	OutFile << "{" << endl  ;

}
void conditionalstat :: Load(ifstream& Infile) {
	Infile >> ID >> left.x >> left.y >> com;
	Text = gauche + aumilieu + droit;

}
void conditionalstat::PrintInfo(Output* pOut) {
	pOut->PrintMessage(com);

}

void conditionalstat::Move(Point p)
{
	left = (p);
	Draw(pro);



}















