#include "Statement.h"
#include "C:\Users\ahmed waleed\OneDrive\Desktop\project\ApplicationManager.h"
#include<iostream>
using namespace std;
 int Statement::IDF = 0;
Statement::Statement(ApplicationManager*a,Point pi,
Point pO, int h, int w,Point l)
{
	height = h;
	width = w;
	pin.x = pi.x;
	pOut.y = pO.y+h;
	
	Text = "";
	left = l;
	Selected = false;
	ID = ++IDF;
}
int Statement::getwidth() {
	return width;
}
int Statement::getheight() {
	return height;
}
int Statement::getid() {
	return ID;
}
Point  Statement::getin() {
	return pin;
}
Point  Statement::getout() {
	return pOut;
}
Point  Statement::getdraw() {
	return ph;
}
Point& Statement::getleft()
{
	return left;
}
void Statement::setdraw(int l)
{
	ph.x = l;
}
void Statement::setdrawy(int l)
{
	ph.y = l;
}
void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

bool Statement::intersection(ApplicationManager* a) {
	Statement** d = a->getstatement();
	
	for (int i = 0; i <a->getrealstat() ; i++)
	{
	

		
		if(((left.x>=d[i]->getleft().x)&&(left.x-40<=d[i]->getleft().x+width+40))|| ((left.x+width+40 >= d[i]->getleft().x-40) && (left.x-100<= d[i]->getleft().x)))

		{
			
			if(((left.y >= d[i]->getleft().y) && (left.y-10 <= d[i]->getleft().y + height+10)) || ((left.y + height + 30 >= d[i]->getleft().y) && (left.y <=d[i]->getleft().y)))
			 
		{
			return true;
		}
			}
	
	}
	return false;
	


	

}