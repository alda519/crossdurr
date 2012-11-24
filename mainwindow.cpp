#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include "questfield.h"
#include "editfield.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionKonec,SIGNAL(activated()), this, SLOT(close()));
    connect(ui->actionOtev_t, SIGNAL(activated()), this, SLOT(otevriKrizovku()));

    //Field * policka[5][5];

    krizovkaWidth = 0;
    krizovkaHeight = 0;

    setMinimumSize(40 + 160 + 5 * 52, 150 + 5 * 52);
    setMaximumSize(40 + 160 + 5 * 52, 150 + 5 * 52);

    // leve menu
    QVBoxLayout * wiwi = new QVBoxLayout;
      // nastaveni velikosti
    wiwi->addWidget(new QLabel("Sirka"));
    //QLineEdit * widthLE = new QLineEdit();
    //widthLE->set;
    wiwi->addWidget(new QLineEdit());
    wiwi->addWidget(new QLabel("Vyska"));
    wiwi->addWidget(new QLineEdit());
    QPushButton * newKrizovkaBtn = new QPushButton(QString("Nastavit"));
    wiwi->addWidget(newKrizovkaBtn);
      // tajenka
    wiwi->addWidget(new QLabel("Tajenka"));
    wiwi->addWidget(new QLineEdit());
    wiwi->addWidget(new QPushButton(QString("Umistit")));
      // cervene tlacitko
    wiwi->addWidget(new QPushButton("Dokocit"));
    ui->widget->setLayout(wiwi);

    connect(newKrizovkaBtn, SIGNAL(pressed()), this, SLOT(novaKrizovka()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::otevriKrizovku()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        QString::fromUtf8("Otevři Křížovku"), "", "Soubory XML(*.xml)");
}

void MainWindow::novaKrizovka()
{
    // smazat co uz tam je
    for (int i = 0; i < krizovkaHeight; ++i) {
        for (int j = 0; j < krizovkaWidth; ++j) {
            delete policka->at(i)[j];
        }
    }

    krizovkaWidth = 15;
    krizovkaHeight = 7;

    // vytvoreni nove mrizky policek
    policka = new QVector< QVector<Field *> > ;
    for (int i = 0; i < krizovkaHeight; ++i)
    {
        QVector<Field *> *policka_buf = new QVector<Field *>;

        for (int j = 0; j < krizovkaWidth; ++j)
        {
            Field * policko;
            // po okraji jsou rovnou policka s
            if(i == 0 || j == 0) {
                policko = new QuestField(j, i, policka);
            } else {
                policko = new EditField(j, i, policka);
            }
            policka_buf->append(policko);
            ui->fields->addWidget(policko,i,j,1,1);
        }
        policka->append(*policka_buf);
    }

    setMinimumSize(40 + 160 + krizovkaWidth * 52, 150 + krizovkaHeight * 52);
    setMaximumSize(40 + 160 + krizovkaWidth * 52, 150 + krizovkaHeight * 52);
}
