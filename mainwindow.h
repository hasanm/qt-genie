#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genie/dat/DatFile.h"
#include "data.h"


QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QComboBox;
class QVBoxLayout;
class QIcon;
class QTableWidget;
class QGridLayout;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
private slots:
  void onLoad();
private:

  genie::DatFile *df; 

  QMenu *fileMenu;
  QAction *loadAction; 
  QAction *exitAction;

  Data data; 

}; 

#endif
