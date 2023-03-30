#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIcon>
#include <QListView>


#include "mainwindow.h"

#include "genie/dat/DatFile.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{

  QWidget *root = new QWidget(this);
  QVBoxLayout *rootLayout = new QVBoxLayout(root);
  
  QWidget *top = new QWidget(this);
  QHBoxLayout *topLayout = new QHBoxLayout(top);

  QWidget *content = new QWidget(this);
  QGridLayout *contentLayout = new QGridLayout(content);


  contentLayout->addWidget(new QLabel("Select"), 0, 0);
  combo = new QComboBox(this);
  contentLayout->addWidget(combo, 0, 1);


  connect(combo, &QComboBox::currentTextChanged, this, &MainWindow::onChange); 

  contentLayout->addWidget(new QLabel("Class"), 1, 0);
  classEdit = new QLineEdit(this);
  contentLayout->addWidget(classEdit, 1, 1);
  contentLayout->addWidget(new QLabel("Name"), 1, 2);
  nameEdit = new QLineEdit(this);
  contentLayout->addWidget(nameEdit, 1, 3);
  contentLayout->addWidget(new QLabel("Speed"), 1, 4);
  speedEdit = new QLineEdit(this);                           
  contentLayout->addWidget(speedEdit, 1, 5);

  armorView = new QListView;
  contentLayout->addWidget(new QLabel("Armor Classes"), 2, 0);
  contentLayout->addWidget(armorView, 2, 1);

  attackView = new QListView;
  contentLayout->addWidget(new QLabel("Attack Classes"), 2, 2);
  contentLayout->addWidget(attackView, 2, 3);

  rootLayout->addWidget(top);
  rootLayout->addWidget(content);
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


      int i = 0;
      std::set<std::uint32_t> used;

      QStringList items;


      for (genie::Civ civ : df->Civs) {
        if (civ.Name != "Gaia") {
          long unitsize = civ.Units.size();
          long unitctr = 0;

          for (genie::Unit unit : civ.Units) {
            unitctr++;

            if (used.find(unit.BaseID) != used.end()) {
              continue; 
            } else {
              used.insert(unit.BaseID);
            }


            if ((unit.BaseID == 38
                                       || unit.BaseID == 4
                                       || unit.BaseID == 6
                                       || unit.BaseID == 7
                                       || unit.BaseID == 8                 
                                       || unit.BaseID == 93
                                       || unit.BaseID == 358
                                       || unit.BaseID == 359
                                       || unit.BaseID == 329
                                       || unit.BaseID == 330
                                       || unit.BaseID == 207
                                       || unit.BaseID == 282
                                       || unit.BaseID == 291
                                       || unit.BaseID == 567
                                       || unit.BaseID == 752
                                       || unit.BaseID == 1234
                                       || unit.BaseID == 1747
                                       || unit.BaseID == 1007
                 || (data.whiteListMap.find(unit.BaseID) != data.whiteListMap.end())
                 )) {
              i++;
              cout << "---------------" << endl;
              cout << unit.Name << ", " << data.unitNames[unit.BaseID] << ", Speed: " << unit.Speed << endl;
              items << QString::fromStdString(unit.Name);
              data.unitMap[unit.BaseID] = unit;
              data.nameMap[unit.Name] = unit.BaseID;
            }

          }
        } 
      }

      QStringListModel *baseModel = new QStringListModel(items,this);

      combo->setModel(baseModel);
         
    }
}

void MainWindow::onChange(const QString &text)
{
  std::uint32_t id = data.nameMap[text.toStdString()]; 
  qDebug() << text << ", " << id;

  genie::Unit unit = data.unitMap[id];

  classEdit->setText(QString("%1").arg(unit.BaseID));
  nameEdit->setText(QString::fromStdString(data.unitNames[id]));
  speedEdit->setText(QString("%1").arg(unit.Speed));



  for (genie::unit::AttackOrArmor attack : unit.Type50.Attacks) {
    cout << "Attack : " << data.armorNames[attack.Class] <<  ", "  << attack.Class << " => "  << attack.Amount << endl;
  }
                        
  QStringList armors;  
  for (genie::unit::AttackOrArmor armor : unit.Type50.Armours) {
    cout << "Armor : " << data.armorNames[armor.Class]<< ", "<< armor.Class << " => "  << armor.Amount << endl;
    armors << QString::fromStdString(data.armorNames[armor.Class]);
    armors << QString("%1").arg(armor.Amount);
  }

  armorModel = new QStringListModel(armors,this);
  armorView->setModel(armorModel);


  
  QStringList attacks; 
  for (genie::unit::AttackOrArmor attack : unit.Type50.Attacks) {
    cout << "Attack : " << data.armorNames[attack.Class] <<  ", "  << attack.Class << " => "  << attack.Amount << endl;
    attacks << QString::fromStdString(data.armorNames[attack.Class]);
    attacks << QString("%1").arg(attack.Amount);
  }

  attackModel = new QStringListModel(attacks, this);
  attackView->setModel(attackModel);
}
