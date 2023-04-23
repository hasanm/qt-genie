#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
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
class QStringListModel;
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
  void onSearch(const QString &text);
private:

  genie::DatFile *df; 

  QMenu *fileMenu;
  QAction *loadAction; 
  QAction *exitAction;


  QComboBox *combo;
  QLineEdit *searchBox; 

  QLineEdit *classEdit;
  QLineEdit *nameEdit;
  QLineEdit *speedEdit;

  QListView *armorView;
  QStringListModel *armorModel;

  QListView *attackView;
  QStringListModel *attackModel; 

  Data data; 

}; 

#endif
