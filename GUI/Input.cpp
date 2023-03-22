#include "Input.h"
#include "Output.h"




Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}


string Input::GetString(Output *pO) const 
{
	string Str;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Str;
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
	
}

string Input::getstringpure(bool &s, Output* pO)
{

	string vs;
	char Key;
	s = true;
	while (1)
	{
		
		
		pWind->WaitKeyPress(Key);
		if (Key == '-' )
		{
			s = false;
			pO->PrintMessage("Please enter a  suitable value");
		}
		if (Key == ')')
		{
			s = false;

			pO->PrintMessage("Please enter a  suitable value");

		}
		if (Key == '(')
		{
			s = false;
			pO->PrintMessage("Please enter a  suitable value");
		}
		if (Key == ',')
		{

			pO->PrintMessage("Please enter a  suitable value");
			s = false;
		}
		else if (Key == '.' )
		{

			pO->PrintMessage("you have entered a dott .");
			s = false;

		}
		else if (Key == 8 && vs.size() > 0)
		{

			if (vs[vs.size() - 1] == '.')
			{
				s = true;
			}
			vs.resize(vs.size() - 1);
			if (vs.size() >= 1)
			{
				pO->PrintMessage(vs);

			}
			if (vs.size() == 0)
			{
				vs = "";
				pO->PrintMessage(vs);

			}
		}
		
		else if (Key > '0' && Key < '9' && vs.size()==0)
		{
			pO->PrintMessage("invalid variable ");
			s = false;
		}
		else if ((Key == 13))
		{
			if (vs == "." || vs == "-" || vs == " -.")
			{
				pO->PrintMessage("invaled");


			}
			else 	//ENTER key is pressed
			{

				

				return vs;
			}
		}
		else
		{	vs += Key;
			s = true;

			pO->PrintMessage(vs);
		
			
		}
	}
}
double Input::GetValue(string &t, Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double vlu;
	string vs = t;
	char Key;
	bool checker = true;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == '-' && vs.size() > 0)
		{

			pO->PrintMessage("Please enter a  suitable value");
		}

		else if (Key == '.' && checker == false)
		{

			pO->PrintMessage("you have entered another dott .");

		}
		else if (Key == 8 && vs.size() > 0)
		{

			if (vs[vs.size() - 1] == '.')
			{
				checker = true;
			}
			vs.resize(vs.size() - 1);
			if (vs.size() >= 1)
			{
				pO->PrintMessage(vs);

			}
			if (vs.size() == 0)
			{
				vs = "";
				pO->PrintMessage(vs);

			}
		}

		else if ((Key < '0' || Key > '9') && (Key != '.') && (Key != '-') && Key != '\r')
		{
			pO->PrintMessage("please enter  a suitable value ");

		}
		else if (Key >= '0' && Key <= '9')
		{
			vs += Key;



			pO->PrintMessage(vs);
		}


		else if ((Key == 13))
		{
			if (vs == "." || vs == "-" || vs == " -.")
			{
				pO->PrintMessage("invaled");


			}
			else 	//ENTER key is pressed
			{

				vlu = stod(vs);

				return vlu;
			}
		}
		else
		{
			if (Key == '.')	 checker = false;
			vs += Key;
			pO->PrintMessage(vs);

		}
	}
}
void Input::updatesize(string t, int& x, int& y) {
	int g, h;
	pWind->GetStringSize(g, h, t);
	x = x + g;
	y = y + h;

}
Statement* Input::intersectselect(ApplicationManager* a, Point n)
{

	Statement** d = a->getstatement();

	for (int i = 0; i < a->getrealstat(); i++)
	{
		if (((n.x+50 >= d[i]->getleft().x) && (n.x - 10 <= d[i]->getleft().x+d[i]->getwidth() + 180)) )
		{
			if (((n.y+30 >= d[i]->getleft().y) && (n.y - 10 <= d[i]->getleft().y + d[i]->getheight() + 70)) )

			{
				return d[i];
			}
		}
	}
}

//ActionType Input::GetUserAction() const
//{	
//	//This function reads the position where the user clicks to determine the desired action
//
//	int x,y;
//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
//
//	if(UI.AppMode == DESIGN )	//application is in design mode
//	{
//		//[1] If user clicks on the Toolbar
//		if ( y >= 0 && y < UI.TlBrWdth)
//		{	//Check whick Menu item was clicked
//			if( x >= 0 && x < UI.MnItWdth  )
//				return ADD_SMPL_ASSIGN;
//			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
//				return ADD_CONDITION;
//			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
//				return EXIT;
//
//			return DSN_TOOL;	//a click on empty part of the tool bar
//		
//		}
//		
//		//[2] User clicks on the drawing area
//		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
//		{
//			return SELECT;	//user want to select/unselect a statement in the flowchart
//		}
//		
//		//[3] User clicks on the status bar
//		return STATUS;
//	}
//	else	//Application is in Simulation mode
//	{
//		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
//	}
//
//}
//

ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.TlBrWdth/1.5  && UI.which==DsgnMenuItem1)
		{
			//Check which Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = ((x / UI.MnItWdth));
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START:return Start;
			case ITM_END:return End;
			case ITM_SWITCH:return SWITCH;
			case ITM_EDIT_STATEMENT:return statementedi;
			case ITM_EDIT_CONNECTION:return connectoredit;
					
			case ITM_COMMENT:return ADD_COMMENT;
			case ITM_SELECT:return SELECT;
			case ITM_MOVE:return MOVE;
			case ITM_COPY:return COPY;
			case	ITM_SIMU:return SIM_MODE;
			case ITM_CUT:return CUT;
			case ITM_CONNECTOR:return ADD_CONNECTOR;
			case ITM_SWITCH1:return switch1;
			default: return DSN_TOOL;

			}
		}
		else if (y >= 0 && y < UI.TlBrWdth / 1.5 && UI.which == DsgnMenuItem2){
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_SWITCH2:return switch2;
			case ITM_PASTE:return PASTE;
			case ITM_MULTISELECT: return MULTI;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_ZIN:return ZOOM_IN;
			case ITM_ZOUT:return  ZOOM_OUT;
			case ITM_EXIT:return EXIT;
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN;
			case ITM_READ:return  READ_STATEMENT;
			case ITM_WRITE:return  WRITE_STATEMENT;
			case ITM_COND: return ADD_CONDITION;
			
				
			default: return DSN_TOOL;
		    }
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.simutoolbarwi)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.simuitemwidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_CHARTVAL: return CHARTVAL;
			case ITM_RUN: return RUN;
			case ITM_STP: return SETBSET;
			case ITM_GENERATE: return GENRATE;
			case ITM_SWITCH_S: return DSN_MODE;
			case ITM_EXIT_S: return EXIT;
			default: return simulationtool;
			}
		}
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar
		
	}

}
Input::~Input()
{
}
