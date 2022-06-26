#include "hero.h"

Hero::Hero(){
    x=0;y=0;
}

Hero::Hero(int x, int y){
    this->x=x;
    this->y=y;
}

void Hero::setPix(QPixmap pix){
     setPixmap(pix);
}

void Hero::addtoScene(QGraphicsScene *scene){
    scene->addItem(this);
}

void Hero::setPosition(){
    setPos(x,y);
}

void Hero::setX(int x){
    this->x=x;
}

void Hero::setY(int y){
    this->y=y;
}

int Hero::getX(){
    return x;
}

int Hero::getY(){
    return y;
}

void Hero::goLeft(){
   setPos(x-=10,y);
}

void Hero::goRight(){
   setPos(x+=10,y);
}

void Hero::goForward(){
   setPos(x,y-=10);
}

void Hero::goBack(){
    setPos(x,y+=10);
}

void Hero::remove(QGraphicsScene *scene)
{
	scene->removeItem(this);
}

Hero::~Hero(){	
    x=0;y=0;
}
