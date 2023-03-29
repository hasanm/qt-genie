#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIcon>


#include "mainwindow.h"

#include "genie/dat/DatFile.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{

  QWidget *root = new QWidget(this);
  QVBoxLayout *rootLayout = new QVBoxLayout(root);
  
  QWidget *top = new QWidget(this);
  QHBoxLayout *topLayout = new QHBoxLayout(top);

  rootLayout->addWidget(top);
  setCentralWidget(root);


  exitAction = new QAction(tr("E&xit"));
  loadAction = new QAction(tr("&Load File"));  

  connect (exitAction , &QAction::triggered, qApp, &QApplication::quit);
  connect (loadAction, &QAction::triggered, this, &MainWindow::onLoad);

  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(loadAction);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAction);
  
  resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);  
}

MainWindow::~MainWindow()
{
}

void MainWindow::onLoad()
{

  QString fileName = QFileDialog::getOpenFileName(this, "Open empires2_x2_p1.dat", "/data", "Dat (*.dat)");
  if (QFile::exists(fileName))
    {
      df = new genie::DatFile();
      df->setGameVersion(genie::GV_LatestDE2);
      qDebug() << "Loading " << fileName << " ...";


      QByteArray ba = fileName.toLocal8Bit();
      const char *c_str2 = ba.data();

      df->load(c_str2);


      QString data; 
      QString classFileName(":/resources/class.txt");
      QFile file(classFileName);
      if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
      }
      else
        {
          qDebug()<<"file opened";
          data = file.readAll();
        }
      
      file.close();

      qDebug()<<data;

      for (genie::Civ civ : df->Civs) {
        if (civ.Name != "Gaia") {

          std::cout << civ.Name << std::endl; 
        } 
      }
         
    }
}
