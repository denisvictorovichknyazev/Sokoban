#ifndef HERO_H
#define HERO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>

class Hero:public QGraphicsPixmapItem
{
public:
    Hero();
    Hero(int x,int y);
    void setPix(QPixmap pix);
    void addtoScene(QGraphicsScene *scene);
    void setPosition();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void goLeft();
    void goRight();
    void goForward();
    void goBack();
	void remove(QGraphicsScene *scene);
    ~Hero();
private:
    int x,y;
};
#endif // HERO_H
