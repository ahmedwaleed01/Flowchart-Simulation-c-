#include "Connector.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Statement.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\start.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\Endd.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\conditionalstat.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\SmplAssign.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\write.h"
#include"C:\Users\ahmed waleed\OneDrive\Desktop\project\Statements\readt.h"
#include<iostream>
using namespace std;
Connector::Connector(ApplicationManager*a,Statement* Src, Statement* Dst, Point P1, Point P2,Input*s)
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{
	SrcStat = Src;
	DstStat = Dst;
	w = s;
	Start = P1;
	End = P2;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	Statement* f;
	Statement* d;
	Statement* e;
	Statement* s;
	Statement* er;
	Statement* es;
	e = dynamic_cast<SmplAssign*>(SrcStat);
	f = dynamic_cast<start*>(SrcStat);
	d = dynamic_cast<Endd*>(SrcStat);
	s = dynamic_cast<conditionalstat*>(SrcStat);
	er = dynamic_cast<write*>(SrcStat);
	es = dynamic_cast<readt*>(SrcStat);
	if (e && !(f || d || s))
	{
		pOut->Drawconnector(SrcStat->getpOutval(), DstStat->getpintval(), "vertical", false);
	}
	else if ((f || d) && !(e || s))
	{
		pOut->Drawconnector(SrcStat->getpOutval(), DstStat->getpintval(), "horiz", false);
	}

	else if (s && !(f || d || e || er))
	{
		if (SrcStat->getpOutval().x < DstStat->getpOutval().x)
		{
			SrcStat->setdraw(SrcStat->getpOutval().x + SrcStat->getwidth() * 2.1);
			SrcStat->setdrawy(SrcStat->getpOutval().y + SrcStat->getheight() / 2.6);
			pOut->Drawconnector(SrcStat->getdraw(), DstStat->getpintval(), "horiz", false);
		}
		else
		{
			SrcStat->setdraw(SrcStat->getpOutval().x - SrcStat->getwidth() * 2.1);
			SrcStat->setdrawy(SrcStat->getpOutval().y + SrcStat->getheight() / 2.6);
			pOut->Drawconnector(SrcStat->getdraw(), DstStat->getpintval(), "horiz", false);

		}
	}
	else if (  er || es){
		if (SrcStat->getpOutval().x < DstStat->getpOutval().x)
		{
			SrcStat->setdraw(SrcStat->getleft().x +3*SrcStat->getwidth() );
			SrcStat->setdrawy(SrcStat->getleft().y+ 0.8 * SrcStat->getheight());
			pOut->Drawconnector(SrcStat->getdraw(), DstStat->getpintval(), "horiz", false);
		}
		else
		{

			SrcStat->setdraw(SrcStat->getleft().x + 3 * SrcStat->getwidth());
			SrcStat->setdrawy(SrcStat->getleft().y + 0.8* SrcStat->getheight());
			pOut->Drawconnector(SrcStat->getdraw(), DstStat->getpintval(), "horiz", false);

		}
	}
	
	}

	
		///TODO: Call output to draw a connector from SrcStat to DstStat on the output window
//pOut->Drawconnector(SrcStat, );

