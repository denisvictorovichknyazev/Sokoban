#include "play.h"

Play::Play(Hero *hero,QGraphicsScene *scene)
{
  this->hero = hero;
  this->scene = scene;
  mas = new int*[6];
  if (mas){
	  for (int i = 0; i < 6; i++){
		  mas[i] = new int[2];
		  if (!mas[i]){
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
  placecoord = new int*[6];
  if (placecoord){
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
  timer = new QTimer();

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
  checkiter = 0;
}

void Play::setCheck(bool check,int i)
{
	gamecheck[i] = check;
}

void Play::initIter()
{
	for (int i = 0; i < 6; i++)
	{
		if (gamecheck[i]==true)
		{
			checkiter++;
		}
	}
}

void Play::action(){
    connect(timer,SIGNAL(timeout()),this,SLOT(play()));
    timer->setInterval(100);
    timer->start();
}

void Play::init(){
	int x = 0, y = 0;
	for (int i = 0; i < 6; i++){
		emit x = boxsignalx(i);
		emit y = boxsignaly(i);
		mas[i][0] = x;
		mas[i][1] = y;
	}
}


void Play::play(){
	if (GetAsyncKeyState(VK_LEFT))
	{
		QPixmap pix("Resorses/MarioLeft.gif");
		hero->setPix(pix);
		hero->goLeft();
		QGraphicsItem * obstacle = itemCollidesWith(hero);
		if (obstacle) {
			if ((obstacle->data(0) == "W") || (obstacle->data(0) == "Place")) {
				hero->goRight();
			}
			else
				if (obstacle->data(0) == "B") {
					double xo = obstacle->x(), yo = obstacle->y();
					for (int i = 0; i < 6; i++)
					{
						if ((xo == mas[i][0]) && (yo == mas[i][1]))
						{
							mas[i][0] -= 10;
							break;
						}
					}
					obstacle->setPos(xo -= 10, yo);
					QGraphicsItem * obstacle1 = itemCollidesWith(obstacle);
					if (obstacle1->data(0) == "Place")
					{
						for (int i = 0; i < 6; i++)
						{
							if (gamecheck[i] == false)
							{
								obstacle->setPos(placecoord[i][0], placecoord[i][1]);
								obstacle->setData(0, "Place");
								for (int j = 0; j < 6; j++){
									if ((xo == mas[j][0]) && (yo == mas[j][1]))
									{
										mas[j][0] = placecoord[i][0];
										mas[j][1] = placecoord[i][1];
										break;
									}
								}
								gamecheck[i] = true;
								checkiter++;
								break;
							}
						}
								if (checkiter == 6)
								{
									emit check();
								}
						return;
					}
					if (itemCollidesWith(obstacle) || itemCollidesWith(hero)) {
						hero->goRight();
						for (int i = 0; i < 6; i++)
						{
							if ((xo == mas[i][0]) && (yo == mas[i][1]))
							{
								mas[i][0] += 10;
								break;
							}
						}
						obstacle->setPos(xo += 10, yo);
						return;

					}

				}
		   }

	}
	else
		if (GetAsyncKeyState(VK_RIGHT))
		{
			QPixmap pix("Resorses/MarioRight.gif");
			hero->setPix(pix);
			hero->goRight();
			QGraphicsItem * obstacle = itemCollidesWith(hero);
			if (obstacle) {
				if ((obstacle->data(0) == "W") || (obstacle->data(0) == "Place")) {
					hero->goLeft();
				}
				else
					if (obstacle->data(0) == "B") {
						double xo = obstacle->x(), yo = obstacle->y();
						for (int i = 0; i < 6; i++)
						{
							if ((xo == mas[i][0]) && (yo == mas[i][1]))
							{
								mas[i][0] += 10;
								break;
							}
						}
						obstacle->setPos(xo += 10, yo);
						QGraphicsItem * obstacle1 = itemCollidesWith(obstacle);
						if (obstacle1->data(0) == "Place")
						{
							for (int i = 0; i < 6; i++)
							{
								if (gamecheck[i] == false)
								{
									obstacle->setPos(placecoord[i][0], placecoord[i][1]);
									obstacle->setData(0, "Place");
									for (int j = 0; j < 6; j++){
										if ((xo == mas[j][0]) && (yo == mas[j][1]))
										{
											mas[j][0] = placecoord[i][0];
											mas[j][1] = placecoord[i][1];
											break;
										}
									}
									gamecheck[i] = true;
									checkiter++;
									break;
								}
							}
							if (checkiter == 6)
							{
								emit check();
							}
							return;
						}
						if (itemCollidesWith(obstacle) || itemCollidesWith(hero)) {
							hero->goLeft();
							for (int i = 0; i < 6; i++)
							{
								if ((xo == mas[i][0]) && (yo == mas[i][1]))
								{
									mas[i][0] -= 10;
									break;
								}
							}
							obstacle->setPos(xo -= 10, yo);
							return;

						}
					}
			 }

		}
		else

			if (GetAsyncKeyState(VK_UP))
			{
				QPixmap pix("Resorses/MarioForward.gif");
				hero->setPix(pix);
				hero->goForward();
				QGraphicsItem * obstacle = itemCollidesWith(hero);
				if (obstacle) {
					if ((obstacle->data(0) == "W") || (obstacle->data(0) == "Place")) {
						hero->goBack();
					}
					else
						if (obstacle->data(0) == "B") {
							double xo = obstacle->x(), yo = obstacle->y();
							for (int i = 0; i < 6; i++)
							{
								if ((xo == mas[i][0]) && (yo == mas[i][1]))
								{
									mas[i][1] -= 10;
									break;
								}
							}
							obstacle->setPos(xo, yo -= 10);
							QGraphicsItem * obstacle1 = itemCollidesWith(obstacle);
							if (obstacle1->data(0) == "Place")
							{
								for (int i = 0; i < 6; i++)
								{
									if (gamecheck[i] == false)
									{
										obstacle->setPos(placecoord[i][0], placecoord[i][1]);
										obstacle->setData(0, "Place");
										for (int j = 0; j < 6; j++){
											if ((xo == mas[j][0]) && (yo == mas[j][1]))
											{
												mas[j][0] = placecoord[i][0];
												mas[j][1] = placecoord[i][1];
												break;
											}
										}
										gamecheck[i] = true;
										checkiter++;
										break;
									}
								}
								if (checkiter == 6)
								{
									emit check();
								}
								return;
							}
							if (itemCollidesWith(obstacle) || itemCollidesWith(hero)) {
								hero->goBack();
								for (int i = 0; i < 6; i++)
								{
									if ((xo == mas[i][0]) && (yo == mas[i][1]))
									{
										mas[i][1] += 10;
										break;
									}
								}
								obstacle->setPos(xo, yo += 10);
								return;
							}
						}

				}


			}
			else
				if (GetAsyncKeyState(VK_DOWN))
				{
					QPixmap pix("Resorses/MarioBack.gif");
					hero->setPix(pix);
					hero->goBack();
					QGraphicsItem * obstacle = itemCollidesWith(hero);
					if (obstacle) {
						if ((obstacle->data(0) == "W") || (obstacle->data(0) == "Place")) {
							hero->goForward();
						}
						else
							if (obstacle->data(0) == "B") {
								double xo = obstacle->x(), yo = obstacle->y();
								for (int i = 0; i < 6; i++)
								{
									if ((xo == mas[i][0]) && (yo == mas[i][1]))
									{
										mas[i][1] += 10;
										break;
									}
								}
								obstacle->setPos(xo, yo += 10);
								QGraphicsItem * obstacle1 = itemCollidesWith(obstacle);
								if (obstacle1->data(0) == "Place")
								{
									for (int i = 0; i < 6; i++)
									{
										if (gamecheck[i] == false)
										{
											obstacle->setPos(placecoord[i][0], placecoord[i][1]);
											obstacle->setData(0, "Place");
											for (int j = 0; j < 6; j++){
												if ((xo == mas[j][0]) && (yo == mas[j][1]))
												{
													mas[j][0] = placecoord[i][0];
													mas[j][1] = placecoord[i][1];
													break;
												}
											}
											gamecheck[i] = true;
											checkiter++;
											break;
										}
									}
									if (checkiter == 6)
									{
										emit check();
									}
									return;
								}
								if (itemCollidesWith(obstacle) || itemCollidesWith(hero)) {
									hero->goForward();
									for (int i = 0; i < 6; i++)
									{
										if ((xo == mas[i][0]) && (yo == mas[i][1]))
										{
											mas[i][1] -= 10;
											break;
										}
									}
									obstacle->setPos(xo, yo -= 10);
									return;
								}

							}
					}

				}
				else{
					QPixmap pix("Resorses/MarioStay.gif");
					hero->setPix(pix);
				}
}

int Play::getBoxmas(int i,int j){
	return mas[i][j];
}

    QGraphicsItem* Play::itemCollidesWith(QGraphicsItem* item)
    {
        QList<QGraphicsItem *> collisions = scene->collidingItems(item);
        foreach (QGraphicsItem* it, collisions) {
                if (it == item)
                     continue;
            return it;
        }
        return NULL;
    }

	Play::~Play()
	{
		delete[] placecoord;
		delete[] gamecheck;
		delete[] mas;		
	}