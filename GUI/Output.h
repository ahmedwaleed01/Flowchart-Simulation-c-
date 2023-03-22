#ifndef OUPTUT_H
#define OUPTUT_H
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\GUI\UI_Info.h"
#include "Input.h"
class Input;
class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	void CreateDesignToolBar1();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateDesignToolBar2();
	void CreateStatusBar();

	Input* CreateInput(); //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void CleartoolBar();
	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void StartOrEnd(Point Left, int width, int height, string Text, bool Selected=false);
	void ReadOrPrint(Point Left, int baseWidth, int width2, int height, string Text, bool Selected=false);
	void ConditionalStatement(Point Left, int width, int height, string Text, bool Selected=false);
	void Drawconnector(Point initial, Point end,string you, bool Selected=false);
	bool Select();
	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should (nector(Point startp, Point endp, bool Selected);
		
	void PrintMessage(string msg);	//Prints a message on Status bar
	
	~Output();
};

#endif