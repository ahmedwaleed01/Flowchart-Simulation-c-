#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Statement.h"
class Output;
class ApplicationManager;
class Statement;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(Point &P) const;//Gets coordinate where user clicks
	string getstringpure(bool&, Output* pO);
	double GetValue(string& t,Output* pO) const;	// Reads a double value from the user 
	bool intersection();
	Statement* intersectselect(ApplicationManager* a,Point n);
void updatesize(string, int&, int&);
	string GetString(Output* pO) const ; //Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	~Input();
};

#endif