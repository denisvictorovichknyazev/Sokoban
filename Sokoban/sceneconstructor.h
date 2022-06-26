#ifndef SCENECONSTRUCTOR_H
#define SCENECONSTRUCTOR_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "hero.h"
#include "loader.h"
#include "box.h"

class SceneConstructor : public QObject
{
    Q_OBJECT
public:
    explicit SceneConstructor(QObject *parent = 0);
    void setScene();
    QGraphicsScene* getScene();
    void showHero(char *name);
    Hero* getHero();
    void makeWalls(char *name);
	void placeBox(char *name);
	int getplaceCoord(int i,int j);
	void makePlaces();
	bool getCheck(int i);
	~SceneConstructor();
private:
    QGraphicsScene *scene;
    Hero *mario;
	QGraphicsItem *walls;
	QGraphicsItem *box;
	Box *boxes;
	QGraphicsItem *place;
	bool* gamecheck;
	int** placecoord;
signals:
     void scenesignal(QGraphicsScene *);
public slots:
	 int boxslotx(int i);
	 int boxsloty(int i);
};

#endif // SCENECONSTRUCTOR_H

