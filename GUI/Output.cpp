#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1400;
	UI.height = 800;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 80;
	UI.TlBrWdth = 80;
	UI.MnItWdth = 55;
	UI.simuitemwidth = 55;
	UI.simutoolbarwi = 1200;
	
	UI.defualt_width=30;
    UI.defualt_height=38;

	UI.DrawClr = BLUE;
	UI.HiClr = RED;
	UI.MsgClr = RED;
	/////////////////////////////////////////////////////////


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar1();
	CreateStatusBar();

}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar1()
{
	UI.AppMode = DESIGN;
	UI.which = DsgnMenuItem1;
	int i=0;	

	//fill the tool bar
	 CleartoolBar();
	 pWind->DrawImage("images/dee.jpeg", 0, 0);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);	

}
void Output::CreateDesignToolBar2()
{
	UI.AppMode = DESIGN;
	UI.which = DsgnMenuItem2;	//Design Mode
	int i = 0;

	//fill the tool bar
	CleartoolBar();
	pWind->DrawImage("images/dees.jpeg",0, 0);
	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);

}


void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	CleartoolBar();
	pWind->DrawImage("images\\SIM.jpeg", 0, 0);
}
void Output::CleartoolBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,-15, UI.width, UI.TlBrWdth);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);
	
}



void Output::Drawconnector(Point startp, Point endp, string you,bool Selected)
{
	Point p1, p2;
	Point betweenp;
	if (Selected) {
		pWind->SetPen(UI.HiClr, 4);
	}
	else {
		pWind->SetPen(UI.DrawClr, 4);
	}
	
	if (abs(startp.x - endp.x) < 8)                               //this mean startp.x = endp.x
	{
		pWind->DrawLine(startp.x, startp.y, endp.x, endp.y);
		if (endp.y > startp.y)
		{
			p1.setp(endp.x + 9, endp.y - 11);                //function drawline invert y on the y-axis 
			p2.setp(endp.x - 9, endp.y - 11);                //so, we made the startp is endp and vice versa to get the correct drawn
		}
		else {
			p1.setp(endp.x + 9, endp.y + 11);
			p2.setp(endp.x - 9, endp.y + 11);

		}
	}
	else if (abs(startp.y - endp.y) < 8)                                //this mean startp.y = endp.y
	{
		pWind->DrawLine(startp.x, startp.y, endp.x, endp.y);
		if (endp.x > startp.x)
		{
			p1.setp(endp.x -9, endp.y + 11);
			p2.setp(endp.x - 9, endp.y - 11);
		}
		else {
			p1.setp(endp.x + 9, endp.y + 11);
			p2.setp(endp.x + 9, endp.y - 11);
		}
	}
	else {
		if (you == "horiz")
		{

			pWind->DrawLine(startp.x, startp.y, endp.x, startp.y);
			pWind->DrawLine(endp.x, startp.y, endp.x, endp.y);

			if ((startp.x > endp.x && startp.y > endp.y)|| (startp.x < endp.x && endp.y < startp.y))
			{
				p1.setp(endp.x + 9, endp.y + 11);
				p2.setp(endp.x - 9, endp.y + 11);

			}
			else if ((startp.x < endp.x && startp.y < endp.y)||(startp.x > endp.x && endp.y > startp.y)) {
				p1.setp(endp.x + 9, endp.y - 11);
				p2.setp(endp.x - 9, endp.y - 11);
			}
		}
		else if (you == "vertical")
		{
			pWind->DrawLine(startp.x, startp.y, startp.x, endp.y);
			pWind->DrawLine(startp.x, endp.y, endp.x, endp.y);

			if ((startp.x > endp.x && startp.y > endp.y) || (startp.x > endp.x && endp.y > startp.y))
			{
				p1.setp(endp.x + 9, endp.y + 11);
				p2.setp(endp.x + 9, endp.y - 11);

			}
			else if (startp.x < endp.x && startp.y < endp.y || (startp.x < endp.x && endp.y < startp.y)) {
				p1.setp(endp.x - 9, endp.y + 11);
				p2.setp(endp.x - 9, endp.y - 11);
			}
		}
	}
	pWind->DrawLine(endp.x, endp.y, p1.x, p1.y);
	pWind->DrawLine(endp.x, endp.y, p2.x, p2.y);
}


//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

// Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color 

	int x, y;

	pWind->GetStringSize(x, y, Text);
	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width + x, Left.y + height, FILLED);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 2, Text);

}
//conditional function
void Output::ConditionalStatement(Point Left, int width, int height, string Text, bool Selected) //Rhombus
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color 

	// array of points 
	int x, y;
	pWind->GetStringSize(x, y, Text);
	width = width + x;
	height = height + x;

	int ipx[4]{ Left.x, Left.x - width / 2,Left.x, Left.x + width / 2 };
	int ipy[4]{ Left.y, Left.y + height / 2 ,Left.y + height, Left.y + height / 2 };

	//Draw the statement block polygon(rhombus)
	pWind->DrawPolygon(ipx, ipy, 4, FILLED);


	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width / 3, Left.y + height / 2.5, Text);

}
//Read or print 

void Output::ReadOrPrint(Point Left, int baseWidth, int width2, int height, string Text, bool Selected) //Parallelogram 
{
	if (Selected)	//if stat is selected, it should be highlighted  
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color    
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color  

//get string size before drawing 
	int x, y;
	pWind->GetStringSize(x, y, Text);

	width2 = width2 + x;
	baseWidth = baseWidth + x;
	height = height + x;

	int ipx[4]{ Left.x, Left.x + width2, Left.x + baseWidth + width2, Left.x + baseWidth };
	int ipy[4]{ Left.y, Left.y + height ,Left.y + height, Left.y };


	//Draw the Parallelogram
	pWind->DrawPolygon(ipx, ipy, 4, FILLED);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + baseWidth / 1.5, Left.y + height / 2, Text);

}

//Start or end function

void Output::StartOrEnd(Point Left, int width, int height, string Text, bool Selected) //ellipse or rectangle with circles on end
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color 

	int x, y;
	pWind->GetStringSize(x, y, Text);
	//Draw ellipse
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width + x, Left.y + height, FILLED);


	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2, Left.y + height / 2.5, Text);

}
bool Output::Select() {
	
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
