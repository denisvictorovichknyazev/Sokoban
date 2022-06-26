#include "box.h"

Box::Box()
{
	x = 0;
	y = 0;
}

Box* Box::operator=(QGraphicsItem* what)
{
	this->x = what->x();
	this->y = what->y();
	return this;
}


int Box::getX(){
	return x;
}

int Box::getY(){
	return y;
}



Box::~Box()
{

}
