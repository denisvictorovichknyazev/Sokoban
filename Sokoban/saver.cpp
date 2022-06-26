#include "saver.h"
#include<QMessageBox>
Saver::Saver(Hero *hero)
{
	this->hero = hero;
	boxmas = new int*[6];
	if (boxmas){
		for (int i = 0; i < 6; i++){
			boxmas[i] = new int[2];
			if (!boxmas[i]){
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	}
	else
	{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
	wallmas = nullptr;
}

void Saver::wallInit(char* name)
{
	Loader *loader = new Loader(name);
	loader->read("W");
	n = loader->getn();
	m = loader->getm();
	wallmas = new int*[loader->getn()];
	if (wallmas){
		for (int i = 0; i < loader->getn(); i++){
			wallmas[i] = new int[loader->getm()];
			if (!wallmas[i]){
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	}
	else{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
	for (int i = 0; i<loader->getn(); i++){
		for (int j = 0; j<loader->getm(); j++){
			wallmas[i][j] = loader->getelem(i, j);
		}
	}
	delete loader;
}

void Saver::boxInit(int i, int j,int ch ){
	boxmas[i][j]=ch;
}

void Saver::wallsAlloc(int col)
{
	n = col;
	m = 4;
	wallmas = new int*[col];
	if (wallmas){
		for (int i = 0; i < col; i++){
			wallmas[i] = new int[4];
			if (!wallmas[i]){
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	}
	else{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
}


void Saver::setWalls(int i, int j, int ch)
{
	wallmas[i][j] = ch;
}

void Saver::save()
{
	ofstream file;
	file.open("Games/save.lvl", ios::out);
	file << "W" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == (m-1))
			{
				file << wallmas[i][j] << endl;
			}
			else
			{
				file << wallmas[i][j] << " ";
			}
		}
	}
	
	file << "H" << endl;
	file << hero->getX() << " " << hero->getY() << endl;
	file << "B" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 1){
				file << boxmas[i][j] <<endl;
			}
			else{
				file << boxmas[i][j] << " ";
			}
		}
	}
	file << "E";
}

void Saver::save(char* name)
{
	ofstream file;
	file.open(name, ios::out);
	file << "W" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == (m - 1))
			{
				file << wallmas[i][j] << endl;
			}
			else
			{
				file << wallmas[i][j] << " ";
			}
		}
	}

	file << "H" << endl;
	file << hero->getX() << " " << hero->getY() << endl;
	file << "B" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 1){
				file << boxmas[i][j] << endl;
			}
			else{
				file << boxmas[i][j] << " ";
			}
		}
	}
	file << "E";
}


Saver::~Saver()
{
	delete[] boxmas;
	delete[] wallmas;
}
