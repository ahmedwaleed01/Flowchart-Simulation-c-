#include "write.h"
#include<iostream>
#include<fstream>
#include <sstream>
write::write(ApplicationManager* a, Point g, string go, string op, int width, int height) :Statement(a, in, out, width, height, g)
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
void write::Save(ofstream& Os)
{
	Os << "Type conditional" << "id= " << ID << " " << left.x << " " << left.y << " " << gauche << " " << aumilieu  << endl;
	Os << com << endl;
	Os.close();
}
bool write::getcheck()
{
	return check;
}


void write::UpdateStatementText()
{
	if (gauche != "Write ")	//No left handside ==>statement have no valid text yet
		Text = "error!";
	else if (aumilieu == "=")
	{
		Text = "error!";
	}
	
		else
		{
			//Build the statement text: Left handside then equals then right handside
			ostringstream T;
			T << gauche << aumilieu ;
			Text = T.str();

		}
}
void write::Draw(Output* pOut) const
{
	pOut->ReadOrPrint(left, width, height, Selected, Text);


}
Point& write::getpOutval()
{
	pOut.x = this->getleft().x + 2*width;
	pOut.y = this->getleft().y + 4.5*height ;

	return pOut;
}
Point& write::getpintval()
{

	pin.x = left.x;
	pin.y = left.y + height / 3.9;

	return pin;
}

void write::Edit() {
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function ");
	gauche = pri->GetString(pro);
	aumilieu = pri->GetString(pro);
	
	UpdateStatementText();

}

void write::Simulate()
{
	
}
void write::GenerateCode(ofstream& OutFile)
{
	OutFile << "cout" << ">>" << aumilieu <<">>" <<"endl" << ";" << endl;

}
void write::PrintInfo(Output* pOut) {
	pOut->PrintMessage(com);

}

void write::Move(Point p)
{
	left = (p);
	Draw(pro);


}



