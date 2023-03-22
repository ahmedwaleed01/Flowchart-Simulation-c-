#pragma once
#include"Statement.h"
#include<string>
class Endd:public Statement
{
private:
	Point in;
	Point out;
	int height;
	int width;
	Point p;
	string txt;
	Connector* c;
	string com;
	ApplicationManager* as;
    void UpdateStatementText();
public:
	void setconnector(Connector* c);
	Connector* getconnector();
	Endd(ApplicationManager* a, Point, int h, int w);
	void Draw(Output* pOut) const;
	void Save(ofstream& Os);	//Save the Statement parameters to a file
	void Load(ifstream& Inf);	//Load the Statement parameters from a file

	Point& getpOutval();
	Point& getpintval();
	void Move(Point p);		//Move the Statement on the flowchart
	void Edit();		//Edit the Statement parameter

	void GenerateCode(ofstream& Of);	//write the statement code to a file
	void Simulate();	//Execute the statement in the simulation mode


	void PrintInfo(Output* pOut);	//print all Statement info on the status bar
	~Endd() {};
};

