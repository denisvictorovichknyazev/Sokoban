#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QGraphicsScene>
#include <QObject>
#include <QMessageBox>
#include "sceneconstructor.h"
#include "play.h"
#include "saver.h"
#include "editform.h"
#include "winform.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
public slots:
    void sceneslot(QGraphicsScene *scene);
    void load_and_play();
    void save();
    void edit();
	void home();
	void exit();
	void check();
private:
    QGraphicsScene *mainscene;
	SceneConstructor *sc;
	Play *player;
	bool playflag;
	char* name;
};

#endif // MAINWINDOW_H
