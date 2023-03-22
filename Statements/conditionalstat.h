#pragma once
#include"Statement.h"
#include<string>
class conditionalstat:public Statement
{
private:
	Point in;
	Point out;
	
	string droit;
	string aumilieu;
	ApplicationManager* A;
	string gauche;
	string com;
	int height;
	int width;
	virtual void UpdateStatementText();
	bool check;
public:
	conditionalstat(ApplicationManager*,Point, string, string, string, int width = UI.defualt_width, int height = UI.defualt_height);
	void Draw(Output* pOut) const;	
	Point& getpoint();
	Point& getpOutval();
	Point& getpintval();
	 void Save(ofstream& OutFile);	
	 void Load(ifstream& Infile) ;	
	 bool getcheck();
	 
  	 void Move(Point) ;		
     void Edit() ;		
	 void Simulate();
	 void GenerateCode(ofstream& OutFile) ;	
	
	 void PrintInfo(Output* pOut);
	
};

