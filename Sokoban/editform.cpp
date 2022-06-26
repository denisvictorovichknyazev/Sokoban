#include "editform.h"
#include "ui_editform.h"
#include<QMessageBox>
#include<QInputDialog>


EditForm::EditForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditForm)
{
	iter = 4;
	boxiter = 0;
	heroitem = new Hero(0, 0);
    ui->setupUi(this);
	mainscene = new QGraphicsScene();
	placecoord = new(std::nothrow) int*[6];
	if (placecoord)
	{
		for (int i = 0; i < 6; i++)
		{
			placecoord[i] = new int[2];
			if (!placecoord[i])
			{
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	}else{
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
	for (int i = 0; i < 6; i++){
		place = mainscene->addPixmap(QPixmap("Resorses/place.png"));
		place->setPos(placecoord[i][0], placecoord[i][1]);
		place->setData(0, "Place");
	}
	ui->hero->setIcon(QIcon("Resorses/MarioStay.gif"));
	ui->box->setIcon(QIcon("Resorses/box.gif"));
	ui->wall->setIcon(QIcon("Resorses/wall.jpg"));
	ui->save->setIcon(QIcon("Resorses/Save.png"));
	ui->toolButton_5->setIcon(QIcon("Resorses/Exit.png"));
	ui->toolButton->setIcon(QIcon("Resorses/undored.png"));
	mainscene->setSceneRect(0, 0, 450, 250);
	mainscene->setBackgroundBrush(QBrush(QColor(0, 0, 0), QPixmap("Resorses/Background.jpg")));
	ui->graphicsView->setScene(mainscene);
	connect(ui->hero, SIGNAL(clicked()), SLOT(hero()));
	connect(ui->box, SIGNAL(clicked()), SLOT(box()));
	connect(ui->wall, SIGNAL(clicked()), SLOT(wall()));
	connect(ui->save, SIGNAL(clicked()), SLOT(save()));
	connect(ui->toolButton_5, SIGNAL(clicked()), SLOT(exit()));
	connect(ui->toolButton, SIGNAL(clicked()), SLOT(restore()));
	ui->toolButton->setEnabled(false);
	ui->save->setEnabled(false);
	boxflag = false;
	wallflag = false;
	heroflag = false;
	wallchange = false;
	herochange = false;
	boxchange = false;
	hcomplete = false;
	bcomplete = false;
	QList<int> sublist;
	sublist.push_back(0);
	sublist.push_back(0);
	sublist.push_back(25);
	sublist.push_back(245);
	wallslist.push_back(sublist);
	sublist.clear();
	sublist.push_back(25);
	sublist.push_back(0);
	sublist.push_back(425);
	sublist.push_back(25);
	wallslist.push_back(sublist);
	sublist.clear();
	sublist.push_back(425);
	sublist.push_back(0);
	sublist.push_back(25);
	sublist.push_back(245);
	wallslist.push_back(sublist);
	sublist.clear();
	sublist.push_back(25);
	sublist.push_back(220);
	sublist.push_back(400);
	sublist.push_back(25);
	wallslist.push_back(sublist);
	sublist.clear();
	QBrush brush(QColor(255, 255, 255), QPixmap("Resorses/wall.jpg"));
	QPen pen(Qt::NoPen);
	wallitem = mainscene->addRect(QRectF(0, 0, 25, 245), pen, brush);
	wallitem = mainscene->addRect(QRectF(25, 0, 425, 25), pen, brush);
	wallitem = mainscene->addRect(QRectF(425, 0, 25, 245), pen, brush);
	wallitem = mainscene->addRect(QRectF(25, 220, 400, 25), pen, brush);
	boxcoord = new(std::nothrow) int*[6];
	if (boxcoord){
		for (int i = 0; i < 6; i++)
		{
			boxcoord[i] = new int[2];
			if (!boxcoord[i])
			{
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	} else
	{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
}

void EditForm::hero()
{ 
	heroflag = true;
	boxflag = false;
	wallflag = false; 
}

void EditForm::box()
{
	heroflag = false;
	boxflag = true;
	wallflag = false;
}



void EditForm::wall()
{
	heroflag = false;
	boxflag = false;
	wallflag = true;
}


void EditForm::mousePressEvent(QMouseEvent *mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton){
		if (heroflag)
		{
			ui->toolButton->setEnabled(true);
			wallchange = false;
			herochange = true;
			boxchange = false;
			ui->hero->setEnabled(false);
			heroflag = false;
			QPixmap pix("Resorses/MarioStay.gif");
			heroitem->setPix(pix);
			heroitem->addtoScene(mainscene);
			heroitem->setX(mouseEvent->x() - 50);
			heroitem->setY(mouseEvent->y() - 50);
			heroitem->setPosition();
			herocoord = new int[2];
			herocoord[0] = mouseEvent->x() - 50;
			herocoord[1] = mouseEvent->y() - 50;
			hcomplete = true;
		}else
		if (wallflag)
		{
			ui->toolButton->setEnabled(true);
			wallchange = true;
			herochange = false;
			boxchange = false;
			iter++;
			QList<int> sublist;
			sublist.push_back(mouseEvent->x() - 45);
			sublist.push_back(mouseEvent->y() - 50);
			sublist.push_back(25);
			sublist.push_back(25);
			wallslist.push_back(sublist);
			sublist.clear();
			QPixmap pix("Resorses/wall.jpg");
			wallitem = mainscene->addPixmap(pix);
			wallitem->setPos(mouseEvent->x() - 45, mouseEvent->y() - 50);
		}else
		if (boxflag)
		{
			ui->toolButton->setEnabled(true);
			wallchange = false;
			herochange = false;
			boxchange = true;
			QPixmap pix("Resorses/box.gif");
			boxitem = mainscene->addPixmap(pix);
			boxitem->setPos(mouseEvent->x() - 45, mouseEvent->y() - 50);
			boxcoord[boxiter][0] = mouseEvent->x() - 45;
			boxcoord[boxiter][1] = mouseEvent->y() - 50;
			boxiter++;
			if (boxiter == 6)
			{
				ui->box->setEnabled(false);
				boxflag = false;
				bcomplete = true;
			}
		}
		if ((bcomplete) && (hcomplete))
         {
			 ui->save->setEnabled(true);
         }

	}
}

void EditForm::wallInit()
{
	QList<int> sublist;
	wallscoord = new(std::nothrow) int*[iter];
	if (wallscoord){
		for (int i = 0; i < iter; i++){
			wallscoord[i] = new int[4];
			if (!wallscoord[i])
			{
				QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
				msgBox.exec();
				std::exit(-1);
			}
		}
	} else 
	{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
	QList<QList<int>>::iterator cur = wallslist.begin();
	QList<QList<int>>::iterator last = wallslist.end();

	int i = 0, j = 0;
	while (cur != last)
	{
		sublist.clear();
		sublist = *cur;
		QList<int>::iterator curs = sublist.begin();
		QList<int>::iterator lasts = sublist.end();
		j = 0;
		while (curs != lasts)
		{
			wallscoord[i][j] = *curs;
			j++;
			++curs;
		}
		i++;
		++cur;
	}
}


void EditForm::save()
{
	bool bOk;
	string namestr="Games/",buf;
	char *name;
	QString str = QInputDialog::getText(0,"Enter name","Enter a name of level: ",QLineEdit::Normal,"level",&bOk);
	if (!bOk) 
	{
		str = "level";
	}
	
	buf = str.toStdString();
	namestr += buf;
	namestr += +".lvl";
	int size = namestr.length();
	name = new char[size+1]; 
	if (name){
		for (int i = 0; i < size; i++)
		{
			name[i] = namestr[i];
		}
		name[size] = '\0';
	}
	else{
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
	Saver *saver = new Saver(heroitem);
	wallInit();
	saver->wallsAlloc(iter);
	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			saver->setWalls(i, j, wallscoord[i][j]);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			saver->boxInit(i, j, boxcoord[i][j]);
		}
	}
	saver->save(name);
	delete saver;
}

void EditForm::exit()
{
	this->close();
}

void EditForm::restore()
{
	if (herochange)
	{
		ui->toolButton->setEnabled(false);
		ui->save->setEnabled(false);
		hcomplete = false;
		delete heroitem;
		heroitem = nullptr;
		heroitem = new Hero(0, 0);
		heroflag = true;
		wallflag = false;
		boxflag = false;
		herochange = false;
		wallchange = false;
		boxchange = false;
	}else
    if (wallchange)
	{
		ui->toolButton->setEnabled(false);
		wallslist.removeLast();
		iter--;
		mainscene->removeItem(wallitem);
		wallflag = true;
		boxflag = false;
		heroflag = false;
		herochange = false;
		wallchange = false;
		boxchange = false;
	}else
	if (boxchange)
	{	
		ui->toolButton->setEnabled(false);
		ui->save->setEnabled(false);
		bcomplete = false;
		boxiter--;
		boxcoord[boxiter][0] = 0;
		boxcoord[boxiter][0] = 0;
		mainscene->removeItem(boxitem);
		wallflag = false;
		boxflag = true;
		heroflag = false;
		herochange = false;
		wallchange = false;
		boxchange = false;
	}

}

EditForm::~EditForm()
{
	delete[] boxcoord;
	delete[] wallscoord;
	delete[] herocoord;
	if (heroitem)
	{
		delete heroitem;
	}
    delete ui;
}
