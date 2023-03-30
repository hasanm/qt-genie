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
class QLineEdit;
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
  void onChange(const QString &text);
private:

  genie::DatFile *df; 

  QMenu *fileMenu;
  QAction *loadAction; 
  QAction *exitAction;


  QComboBox *combo;

  QLineEdit *classEdit;
  QLineEdit *nameEdit;
  QLineEdit *speedEdit; 

  Data data; 

}; 

#endif
