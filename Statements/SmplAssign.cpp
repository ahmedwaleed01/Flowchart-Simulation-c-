#include "SmplAssign.h"
#include <sstream>
#include<fstream>
using namespace std;

SmplAssign::SmplAssign(ApplicationManager*a,Point Lcorner, int w, int h,string LeftHS, double RightHS):Statement(a,Inlet,Outlet, UI.ASSGN_WDTH ,UI.ASSGN_HI,Lcorner)
{
	LHS = LeftHS;
	RHS = RightHS;
	width = w;
	height = h;
	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}
Point& SmplAssign::getpOutval()
{

	pOut.x = left.x+width/1.4 ;
	pOut.y = left.y +1.5*height;
	return pOut;
}
Point& SmplAssign::getpintval()
{

	pin.x = left.x + width / 1.2;
	pin.y = left.y;
	return pin;
}
void SmplAssign::GenerateCode(ofstream& OutFile) {
	OutFile <<LHS << "=" << RHS  << endl;
	OutFile << "}" << endl;

}
void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.defualt_width, UI.defualt_height, Text, Selected);
	
}
string m="";
void SmplAssign::Edit() {
	pro->ClearStatusBar();
	pro->PrintMessage("Edit Function ");
	LHS = pri->GetString(pro);
	RHS = pri->GetValue(m, pro);


	UpdateStatementText();

}

//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}
void SmplAssign::Save(ofstream& Os)
{
	Os << "Type simplassigne" << "id= " << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << "=" << " " <<RHS << endl;
	Os << com << endl;
	Os.close();
}
void  SmplAssign::PrintInfo(Output* pOut) {
	pOut->PrintMessage(com);

}


	void SmplAssign::Move(Point p)
	{
		left = (p);
		Draw(pro);


	}

