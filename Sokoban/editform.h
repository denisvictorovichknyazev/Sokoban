#ifndef EDITFORM_H
#define EDITFORM_H

#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QMouseEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>
#include "saver.h"
#include "hero.h"
namespace Ui {
class EditForm;
}
using namespace std;
class EditForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditForm(QWidget *parent = 0);
    ~EditForm();

private:
    Ui::EditForm *ui;
	QGraphicsScene *mainscene;
	Hero *heroitem;
    QGraphicsItem *wallitem;
	QGraphicsItem *boxitem;
	QGraphicsItem *place;
	bool wallflag;
	bool heroflag;
	bool boxflag;
	bool wallchange;
	bool herochange;
	bool boxchange;
	bool hcomplete;
	bool bcomplete;
	int* herocoord;
	QList<QList<int>> wallslist;
	int** boxcoord;
	int** wallscoord;
	int** placecoord;
	int iter;
	int boxiter;
	void mousePressEvent(QMouseEvent * mouseEvent);
	void wallInit();
private slots:
	void hero();
	void wall();
	void box();
	void exit();
	void restore();
	void save();
};

#endif // EDITFORM_H
