#ifndef SAVER_H
#define SAVER_H

#include <QObject>
#include "loader.h"
#include "hero.h"
#include <fstream>
using namespace std;
class Saver : public QObject
{
	Q_OBJECT

public:
	Saver(Hero *hero);
	void wallInit(char* name);
	void boxInit(int i, int j, int ch);
	void wallsAlloc(int col);
	void setWalls(int i, int j, int ch);
	void save();
	void save(char* name);
	~Saver();
private:
	Hero *hero;
	int **boxmas;
	int **wallmas;
	int m, n;
};

#endif // SAVER_H
