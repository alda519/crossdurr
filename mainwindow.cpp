#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include "questfield.h"
#include "editfield.h"
#include <QString>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionKonec,SIGNAL(activated()), this, SLOT(close()));
    connect(ui->actionOtev_t, SIGNAL(activated()), this, SLOT(otevriKrizovku()));

    krizovkaWidth = 0;
    krizovkaHeight = 0;

    setMinimumSize(40 + 160 + 5 * 52, 250 + 5 * 52);
    setMaximumSize(40 + 160 + 5 * 52, 250 + 5 * 52);

    vytvorLusticiListu();
    vytvorVytvareciListu();

    ui->widgetVytvareni->setLayout(listaVytvareni);
    ui->widgetLusteni->setLayout(listaLusteni);

    zobrazVytvareciListu();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * menu vlevo naboku, zobrazuje se jenom pri vytvareni krizovky
 */
void MainWindow::vytvorVytvareciListu()
{

    listaVytvareni = new QVBoxLayout;
      // nastaveni velikosti
    listaVytvareni->addWidget(new QLabel("Sirka"));
    kSirka = new QLineEdit("15");
    kVyska = new QLineEdit("10");
    listaVytvareni->addWidget(kSirka);
    listaVytvareni->addWidget(new QLabel("Vyska"));
    listaVytvareni->addWidget(kVyska);
    QPushButton * newKrizovkaBtn = new QPushButton(QString("Nastavit velikost"));
    listaVytvareni->addWidget(newKrizovkaBtn);
      // tajenka
    listaVytvareni->addWidget(new QLabel("Tajenka"));
    tAjenka = new QTextEdit("DESNE SUPER TAJENKA");
    tAjenka->setMaximumWidth(160);
    tAjenka->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    listaVytvareni->addWidget(tAjenka);
    listaVytvareni->addWidget(new QPushButton(QString("Umistit tajenku")));
        // tooly
//    listaVytvareni->addWidget(new QRadioButton("AAAA"));
//    listaVytvareni->addWidget(new QRadioButton("BBBB"));
//    listaVytvareni->addWidget(new QRadioButton("CCCC"));


     createActions();
     listaVytvareni->addWidget(tools);


      // cervene tlacitko
    QPushButton * finishBtn = new QPushButton("Doplnit prazdne");
    finishBtn->setStyleSheet("background-color: #ff3333;");
    listaVytvareni->addWidget(finishBtn);

    QPushButton * lustitBtn = new QPushButton("Lustit");
    lustitBtn->setStyleSheet("background-color: #ff3333;");
    listaVytvareni->addWidget(lustitBtn);

    connect(newKrizovkaBtn, SIGNAL(pressed()), this, SLOT(novaKrizovka()));
    connect(finishBtn, SIGNAL(pressed()), this, SLOT(vyplnitNesmyslama()));
    connect(lustitBtn, SIGNAL(pressed()), this, SLOT(zobrazLusticiListu()));

}

/*
 * menu vlevo naboku, zobrazuje se jenom pri lusteni
 */
void MainWindow::vytvorLusticiListu()
{
    listaLusteni = new QVBoxLayout;
      // nastaveni velikosti

      // tajenka
    listaLusteni->addWidget(new QLabel("Tajenka"));
    tAjenka = new QTextEdit("DESNE SUPER TAJENKA");
    tAjenka->setMaximumWidth(160);
    tAjenka->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    listaLusteni->addWidget(tAjenka);
    listaLusteni->addWidget(new QPushButton(QString("Umistit tajenku")));

    QPushButton * editorBtn = new QPushButton("Zpet do editoru");
    editorBtn->setStyleSheet("background-color: #ff3333;");
    listaLusteni->addWidget(editorBtn);
    connect(editorBtn, SIGNAL(pressed()), this, SLOT(zobrazVytvareciListu()));

}

void MainWindow::createActions()
{
    actEdit = new QAction("pismeno",this);
    actEdit->setStatusTip("Prazdne policko pro 1 pismeno");
    connect(actEdit,SIGNAL(triggered()),this,SLOT(selectEdit()));

    actTajenka = new QAction("tajenka",this);
    actTajenka->setStatusTip("Prazdne policko pro 1 pismeno tajenky");
    connect(actTajenka,SIGNAL(triggered()),this,SLOT(selectTajenka()));

    actSymbol = new QAction("symbol",this);
    actSymbol->setStatusTip("Pro vyplneni rohu");
    connect(actSymbol,SIGNAL(triggered()),this,SLOT(selectSymbol()));

    actQuest = new QAction("zadani",this);
    actQuest->setStatusTip("Policko se zadanim pro 1 slovo");
    connect(actQuest,SIGNAL(triggered()),this,SLOT(selectQuest()));

    actTools = new QActionGroup(this);
    actTools->addAction(actEdit);
    actTools->addAction(actTajenka);
    actTools->addAction(actSymbol);
    actTools->addAction(actQuest);

    tools = new QToolBar();
    tools->addAction(actEdit);
    tools->addAction(actTajenka);
    tools->addAction(actSymbol);
    tools->addAction(actQuest);

}

void MainWindow::zobrazVytvareciListu()
{
    ui->widgetVytvareni->setVisible(true);
    ui->widgetLusteni->setVisible(false);
}

void MainWindow::zobrazLusticiListu()
{
    ui->widgetVytvareni->setVisible(false);
    ui->widgetLusteni->setVisible(true);

}

void MainWindow::selectEdit()
{
    qDebug() << "edit" << endl;
}

void MainWindow::selectTajenka()
{
    qDebug() << "tajenka" << endl;
}

void MainWindow::selectSymbol()
{
    qDebug() << "symbol" << endl;
}

void MainWindow::selectQuest()
{
    qDebug() << "quest" << endl;
}

void MainWindow::otevriKrizovku()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        QString::fromUtf8("Otevři Křížovku"), "", "Soubory XML(*.xml)");
}

#define MAX(a,b) (((a)>(b))?(a):(b))

void MainWindow::novaKrizovka()
{
    // smazat co uz tam je
    for (int i = 0; i < krizovkaHeight; ++i) {
        for (int j = 0; j < krizovkaWidth; ++j) {
            delete policka->at(i)[j];
        }
    }

    krizovkaHeight = kVyska->text().toInt();
    krizovkaWidth = kSirka->text().toInt();

    // vytvoreni nove mrizky policek
    policka = new QVector< QVector<Field *> > ;
    for (int i = 0; i < krizovkaHeight; ++i)
    {
        QVector<Field *> *policka_buf = new QVector<Field *>;

        for (int j = 0; j < krizovkaWidth; ++j)
        {
            Field * policko;
            // po okraji jsou rovnou policka s
            if(i == 0 || j == 0 || i + 3 == j || 13- i == j) {
                policko = new QuestField(j, i, policka);
            } else {
                policko = new EditField(j, i, policka);
            }
            policka_buf->append(policko);
            ui->fields->addWidget(policko,i,j,1,1);
        }
        policka->append(*policka_buf);
    }

    // resize okna a nastaveni nejakych minimalnich rozmeru, funguje to blbe, ale aspon neco
    setMinimumSize(40 + 160 + MAX(krizovkaWidth,5) * 52, 150 + MAX(krizovkaHeight, 5) * 52);
    setMaximumSize(40 + 160 + MAX(krizovkaWidth,5) * 52, 150 + MAX(krizovkaHeight, 5) * 52);
}


void MainWindow::vyplnitNesmyslama()
{
    for (int i = 0; i < krizovkaHeight; ++i) {
        for (int j = 0; j < krizovkaWidth; ++j) {
            policka->at(i)[j]->setRandomText();
        }
    }
}
