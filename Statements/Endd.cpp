#include "Endd.h"
#include<fstream>

void Endd::setconnector(Connector* c)
{
	this->c = c;
}
Connector* Endd::getconnector()
{
	return c;
}
Endd::Endd(ApplicationManager* a, Point g, int width, int height) :Statement(a,in, out, width, height, g)
{
	as = a;
	c = NULL;
	txt = "End";
	//UpdateStatementText();
	this->width = width;
	this->height = height;
}
void Endd::UpdateStatementText()
{
}

void Endd::Draw(Output* pOut) const
{
	pOut->StartOrEnd(left, width, height, txt, Selected);
}

void Endd::Save(ofstream& Os)
{
	Os << "Type end" << "id= " << ID << " " << left.x << " " << left.y << endl;
	Os << com << endl;
	Os.close();

}
void Endd::Load(ifstream& Inf)
{
	Inf >> ID >> left.x >> left.y >> com;
	Text = "End";
	UpdateStatementText();
}
void Endd::Move(Point p)
{
	left = (p);
	Draw(pro);

}
Point& Endd::getpOutval()
{

	pOut.x = left.x +width /2.1;
	pOut.y = left.y+height  ;
	return pOut;
	}
Point& Endd::getpintval()
{

	pin.x = left.x + width /1.2 ;
	pin.y = left.y ;
	return pin;
}
void Endd::Edit()
{
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function is called and you cannot edit! ");
	Point v;
	pri->GetPointClicked(v);
	pro->ClearStatusBar();
}

void Endd::GenerateCode(ofstream& Of)
{
	Of << "return 0;" << endl << "}";
}

void Endd::Simulate()
{
}

void Endd::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(com);
}
