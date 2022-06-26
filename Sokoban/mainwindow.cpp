#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	playflag = false;
	ui->saveButton->setEnabled(false);
	ui->homeButton->setEnabled(false);
	ui->homeButton->setIcon(QIcon("Resorses/Home.png"));
	ui->loadButton->setIcon(QIcon("Resorses/Load.jpg"));
	ui->exitButton->setIcon(QIcon("Resorses/Exit.png"));
	ui->saveButton->setIcon(QIcon("Resorses/Save.png"));
	ui->editButton->setIcon(QIcon("Resorses/Edit.png"));
	try{
		mainscene = new QGraphicsScene();
	}
	catch (bad_alloc){
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1);
	}
	sc = nullptr;
	player = nullptr;
    mainscene->setSceneRect(0, 0, 515, 305);
    mainscene->addPixmap(QPixmap("Resorses/MainPicture.jpg"));
    ui->graphicsView->setScene(mainscene);
    connect(ui->editButton, SIGNAL(clicked()), SLOT(edit()));
    connect(ui->saveButton, SIGNAL(clicked()), SLOT(save()));
    connect(ui->loadButton, SIGNAL(clicked()), SLOT(load_and_play()));
	connect(ui->homeButton, SIGNAL(clicked()), SLOT(home()));
	connect(ui->exitButton, SIGNAL(clicked()), SLOT(exit()));
}

void MainWindow::sceneslot(QGraphicsScene *scene){
    ui->graphicsView->setScene(scene);
}

void MainWindow::load_and_play(){
  QString fileName=QFileDialog::getOpenFileName(this, "Load level","Games/","Level files(*.lvl)");
  if (fileName != ""){
	  ui->homeButton->setEnabled(true);
	  ui->saveButton->setEnabled(true);
	  ui->loadButton->setEnabled(false);
	  ui->editButton->setEnabled(false);
	  try
	  {
		  name = new char[fileName.size() + 1];
	  }
	  catch (bad_alloc)
	  {
		  QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		  msgBox.exec();
		  std::exit(-1);
	  }
	  qstrncpy(name, qPrintable(fileName), fileName.size() + 1);
	  try{
		  sc = new SceneConstructor();
	  }
	  catch (bad_alloc)
	  { 
		QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		msgBox.exec();
		std::exit(-1); 
	  }
	  connect(sc, SIGNAL(scenesignal(QGraphicsScene*)), this, SLOT(sceneslot(QGraphicsScene*)));
	  sc->setScene();
	  sc->showHero(name);
	  sc->makeWalls(name);
	  sc->makePlaces();
	  sc->placeBox(name);
	  try{
		  player = new Play(sc->getHero(), sc->getScene());
	  }
	  catch (bad_alloc){
		  QMessageBox msgBox(QMessageBox::Critical, "Exit game", "Not enough memory on your computer", QMessageBox::Ok);
		  msgBox.exec();
		  std::exit(-1);
	  }
	  connect(player, SIGNAL(boxsignalx(int)), sc, SLOT(boxslotx(int)));
	  connect(player, SIGNAL(boxsignaly(int)), sc, SLOT(boxsloty(int)));
	  connect(player, SIGNAL(check()), SLOT(check()));
	  player->init();
	  for (int i = 0; i < 6; i++)
	  {
		  player->setCheck(sc->getCheck(i), i);
	  }
	  player->initIter();
	  playflag = true;
	  player->action();
  }

}

void MainWindow::check()
{
	WinForm *form = new WinForm();
	form->exec();
	playflag = false;
	ui->loadButton->setEnabled(true);
	ui->editButton->setEnabled(true);
	ui->homeButton->setEnabled(false);
	ui->saveButton->setEnabled(false);
	mainscene->setSceneRect(0, 0, 515, 305);
	mainscene->addPixmap(QPixmap("Resorses/MainPicture.jpg"));
	ui->graphicsView->setScene(mainscene);
	if (sc)
	{
		delete sc;
		sc = nullptr;
	}
	if (player)
	{
		delete player;
		player = nullptr;
	}
}

void MainWindow::save(){
	Saver *saver =new Saver(sc->getHero());
	saver->wallInit(name);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			saver->boxInit(i, j, player->getBoxmas(i, j));
		}
	}
	saver->save();
	delete saver;
}


void MainWindow::home(){
	QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Exit game", "Are you sure to exit this game?\nAll unsaved progress will be lost.",QMessageBox::Yes | QMessageBox::No);
	if (msgBox->exec() == QMessageBox::Yes)
	{ 
		playflag = false;
		ui->loadButton->setEnabled(true);
		ui->editButton->setEnabled(true);
		ui->homeButton->setEnabled(false);
		ui->saveButton->setEnabled(false);
		mainscene->setSceneRect(0, 0, 515, 305);
		mainscene->addPixmap(QPixmap("Resorses/MainPicture.jpg"));
		ui->graphicsView->setScene(mainscene);
		if (sc)
		{
			delete sc;
			sc = nullptr;
		}
		if (player)
		{
			delete player;
			player = nullptr;
		}
	}
}

void MainWindow::exit(){
	if (playflag){
		QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Exit program", "Are you sure?\nAll unsaved progress will be lost.", QMessageBox::Yes | QMessageBox::No);
		if (msgBox->exec() == QMessageBox::Yes)
		{
			this->close(); 
		}
	}
	else{
		QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Exit program", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
		if (msgBox->exec() == QMessageBox::Yes)
		{
			if (sc)
			{
				delete sc;
				sc = nullptr;
			}
			if (player)
			{
				delete player;
				player = nullptr;
			}
			this->close();
		}
	}
}


void MainWindow::edit(){
	EditForm *form = new EditForm();
	form->show();
}



MainWindow::~MainWindow()
{ 
	if (sc)
	{
		delete sc;
	}
	if (player)
	{
		delete player;
	}
    delete ui;
}
