#ifndef BOX_H
#define BOX_H

#include <QGraphicsItem>

class Box 
{
public:
	Box();
	int getX();
	int getY();
	Box* operator=(QGraphicsItem* what);
	~Box();
private:
	int x, y;
};
#endif // BOX_H