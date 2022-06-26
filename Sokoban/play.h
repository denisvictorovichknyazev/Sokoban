#ifndef PLAY_H
#define PLAY_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QTimer>
#include <QList>
#include <windows.h>
#include "hero.h"


class Play:public QObject
{
   Q_OBJECT
public:
    Play(Hero *hero,QGraphicsScene* scene);
	void action();
	void init();
	int getBoxmas(int i,int j);
	void setCheck(bool check,int i);
	void initIter();
	~Play();
private:
    Hero *hero;
    QGraphicsScene *scene;
    QTimer *timer;
    QGraphicsItem* itemCollidesWith(QGraphicsItem * item);
	int** mas;
	int** placecoord;
	bool* gamecheck;
	int checkiter;
public slots:
    void play();
signals:
	int boxsignalx(int i);
	int boxsignaly(int i);
	void check();
};

#endif // PLAY_H
