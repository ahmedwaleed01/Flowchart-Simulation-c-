#ifndef SMPL_ASSIGN_H
#define SMPL_ASSIGN_H
#include<string>
#include "Statement.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SmplAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	string com;
	Connector *pConn;	//Simple Assignment Stat. has one Connector to next statement
	ApplicationManager* A;
	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement
	int width;
	int height;
	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	SmplAssign(ApplicationManager*a,Point Lcorner, int, int,string LeftHS="", double RightHS=0);
	Point& getpOutval();
	Point& getpintval();
	void setLHS(const string &L);
	void setRHS(double R);
	void PrintInfo(Output* pOut);
	void  Move(Point p);
	virtual void Draw(Output* pOut) const;
	Point& getpoint();

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	bool getcheck();

	void Move();
	void Edit();
	void Simulate();
	void GenerateCode(ofstream& OutFile);

	
	

};

#endif