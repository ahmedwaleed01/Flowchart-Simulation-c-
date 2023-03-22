#ifndef STATEMENT_H++

#define STATEMENT_H

#include "..\defs.h"
#include "Connector.h"
class Input;
#include "..\GUI\Output.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\GUI\Input.h"
#include "..\ApplicationManager.h"
class ApplicationManager;
//Base class for all Statements
class Statement
{
protected:
	int ID;		
	static int IDF;	//Each Statement has an ID
	string Text;	//Statement text (e.g.  "X = 5" OR "if(salary > 3000)" and so on )
	bool Selected;	//true if the statement is selected on the folwchart
	Point pin;
	Point pOut;
	Point ph;
	Output* pro;
	window* w;
	Input* pri;
	Point left;
	int height;
	int width;
	virtual void UpdateStatementText() =0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement(ApplicationManager* a,Point,Point,int,int,Point);
	void SetSelected(bool s);
	bool IsSelected() const;
	void deletestatement();
	virtual Point& getpOutval()=0;
	virtual Point& getpintval()=0;
	bool intersection(ApplicationManager* a);
	Point& getleft();
	
	Statement* selected(ApplicationManager* a,Point);
	Point getin();
	Point getout();
	int getwidth();
	Point  getdraw();
	void  setdrawy(int);
	void  setdraw(int);
	int getid();
	int getheight();
	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	
	Point& getpoint();

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	


	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file
	

	virtual void Move(Point) = 0;		//Move the Statement on the flowchart
	virtual void Edit() = 0;		//Edit the Statement parameter

	virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file
//	virtual void Simulate();	//Execute the statement in the simulation mode


	virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	
	///TODO: Add more functions if needed
};

#endif