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
}
