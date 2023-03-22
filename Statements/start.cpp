#include "start.h"
#include<fstream>
void start::setconnector(Connector* c)
{
	this->c = c;
}
Connector* start::getconnector()
{
	return c;
}
start::start(ApplicationManager* a, Point g, int width, int height):Statement(a,in, out, width, height,g)
{
	
	c = NULL;
	txt = "Start";
	Text = txt;
	this->width = width;
	this->height = height;
	po=a->GetOutput();
}
void start::UpdateStatementText()
{
}
Point& start::getpOutval()
{

	pOut.x = left.x + width / 1.2;
	pOut.y = left.y + height;
	return pOut;
}
Point& start::getpintval()
{

	pin.x = left.x + width / 1.2;
	pin.y = left.y;
	return pin;
}
void start::Draw(Output* pOut) const
{
	pOut->StartOrEnd(left, width, height, txt, Selected);
}

void start::Save(ofstream& Os)
{
	Os << "Type Start" << "id= " << ID << " " << left.x << " " << left.y << endl;
	Os << com << endl;
	Os.close();

}
void start::Load(ifstream& Inf)
{
	Inf >> ID >> left.x >> left.y >> com;
	Text = "Start";
}

void start::Move(Point p)
{
	left = (p);
	Draw(po);

}

void start::Edit()
{
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function is called and you cannot edit! ");
	Point v;
	pri->GetPointClicked(v);
	pro->ClearStatusBar();
}

void start::GenerateCode(ofstream& Of)
{
	Of << "#include <iostream>"<<endl<<"using namespace std;"<<endl;
	Of << "int main()" << endl << "{";
}

void start::Simulate()
{
}

void start::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(com);
}