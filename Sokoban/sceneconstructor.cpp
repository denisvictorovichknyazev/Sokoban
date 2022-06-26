#include "sceneconstructor.h"
#include <QMessageBox>
SceneConstructor::SceneConstructor(QObject *parent) : QObject(parent)
{
      scene = new QGraphicsScene();
      scene->setSceneRect(0, 0, 450, 250);
	  placecoord = new int*[6];
	  if (placecoord)
	  {
		  for (int i = 0; i < 6; i++)
		  {
			  placecoord[i] = new int[2];
			  if (!placecoord[i]){
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
	  placecoord[0][0] = 25;
	  placecoord[0][1] = 24;

	  placecoord[1][0] = 25;
	  placecoord[1][1] = 42;

	  placecoord[2][0] = 25;
	  placecoord[2][1] = 60;
	  
	  placecoord[3][0] = 42;
	  placecoord[3][1] = 24;
	  
	  placecoord[4][0] = 42;
	  placecoord[4][1] = 42;
      
	  placecoord[5][0] = 42;
	  placecoord[5][1] = 60;
	  gamecheck = new bool[6]; 
	  if (gamecheck){
		  for (int i = 0; i < 6; i++)
		  {
			  gamecheck[i] = false;
		  }
	  }
	  else{
		  QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		  msgBox.exec();
		  std::exit(-1);
	  }
	  
	  mario=new Hero(0,0);
}

void SceneConstructor::setScene(){
    emit scenesignal(scene);
    scene->setBackgroundBrush(QBrush(QColor(0,0,0), QPixmap("Resorses/Background.jpg")));
}

void SceneConstructor::showHero(char *name){
    Loader *loader = new Loader(name);
    loader->read("H");
    QPixmap pix("Resorses/MarioStay.gif");
        mario->setPix(pix);
        mario->addtoScene(scene);
        mario->setData(0,"M");
        int x = loader->getelem(0,0);
        int y = loader->getelem(0,1);
        mario->setX(x);
        mario->setY(y);
        mario->setPosition();
     delete loader;
}

void SceneConstructor::makeWalls(char *name){
    Loader *loader = new Loader(name);
    loader->read("W");
    int **wall=new int*[loader->getn()];
	if (wall){
		for (int i = 0; i < loader->getn(); i++){
			wall[i] = new int[loader->getm()];
			if (!wall[i]){
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
    for(int i=0;i<loader->getn();i++){
      for(int j=0;j<loader->getm();j++){
          wall[i][j]=loader->getelem(i,j);
      }
    }
    QBrush brush(QColor(255, 255, 255), QPixmap("Resorses/wall.jpg"));
    QPen pen(Qt::NoPen);
    for (int i = 0; i < loader->getn(); i++) {
        walls=scene->addRect(QRectF(wall[i][0], wall[i][1], wall[i][2], wall[i][3]), pen, brush);
        walls->setData(0, "W");
    }
     delete loader;
}

void SceneConstructor::placeBox(char *name)
{
    Loader *loader = new Loader(name);
    loader->read("B");
	boxes = new Box[6];
    for(int i=0;i<loader->getn();i++){
    box = scene->addPixmap(QPixmap("Resorses/box.gif"));
    box->setPos(loader->getelem(i,0), loader->getelem(i,1));
	for (int j = 0; j < 6; j++)
	{
		if ((loader->getelem(i, 0) == placecoord[j][0]) && (loader->getelem(i, 1) == placecoord[j][1]))
		{
			gamecheck[j] = true;
			break;
		}
	}
		boxes[i] = box;
		box->setData(0, "B");
		
    }
    delete loader;
}

int SceneConstructor::getplaceCoord(int i,int j)
{
	return placecoord[i][j];
}

bool SceneConstructor::getCheck(int i)
{
	return gamecheck[i];
}

void SceneConstructor::makePlaces()
{
	for (int i = 0; i < 6; i++){
		place = scene->addPixmap(QPixmap("Resorses/place.png"));
		place->setPos(placecoord[i][0], placecoord[i][1]);
		place->setData(0, "Place");
	}
}

 QGraphicsScene* SceneConstructor::getScene(){
     return scene;
 }

Hero* SceneConstructor::getHero(){
     return mario;
 }

int SceneConstructor::boxslotx(int i){
	int x = 0;
		x = boxes[i].getX();
		return x;
			
	}

int SceneConstructor::boxsloty(int i){
	int y = 0;
	y = boxes[i].getY();
	return y;

}



SceneConstructor::~SceneConstructor()
{
	delete mario;
	delete[] placecoord;
}
