#ifndef CONNECTOR_H
#define CONNECTOR_H
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include "..\GUI\UI_Info.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
class Statement;
class Output;
class Input;
class ApplicationManager;
class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement* SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start  of the connector
	Point End;	
	Input* w;	//End point of the connector
	ApplicationManager* a;
public:
	Connector(ApplicationManager*,Statement* Src, Statement* Dst,Point,Point,Input*);
	
	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;
	

};

#endif