#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionKonec,SIGNAL(activated()), this, SLOT(close()));
    connect(ui->actionOtev_t, SIGNAL(activated()), this, SLOT(otevriKrizovku()));

    //Field * policka[5][5];

    int krizovkaWidth = 15, krizovkaHeight = 7;

    setMinimumSize(40 + 160 + krizovkaWidth * 52, 150 + krizovkaHeight * 52);
    setMaximumSize(40 + 160 + krizovkaWidth * 52, 150 + krizovkaHeight * 52);
    //resize(40 + 160 + krizovkaWidth * 52, 150 + krizovkaHeight * 52 );s

    // leve menu
    QVBoxLayout * wiwi = new QVBoxLayout;
      // nastaveni velikosti
    wiwi->addWidget(new QLabel("Sirka"));
    wiwi->addWidget(new QLineEdit());
    wiwi->addWidget(new QLabel("Vyska"));
    wiwi->addWidget(new QLineEdit());
    wiwi->addWidget(new QPushButton(QString("Nastavit")));
      // tajenka
    wiwi->addWidget(new QLabel("Tajenka"));
    wiwi->addWidget(new QLineEdit());
    wiwi->addWidget(new QPushButton(QString("Umistit")));
      // cervene tlacitko
    wiwi->addWidget(new QPushButton("Dokocit"));
    ui->widget->setLayout(wiwi);

    // vytvoreni nove mrizky policek
    policka = new QVector< QVector<Field *> > ;
    for (int i = 0; i < krizovkaHeight; ++i)
    {
        QVector<Field *> *policka_buf = new QVector<Field *>;

        for (int j = 0; j < krizovkaWidth; ++j)
        {            
            Field * policko = new Field(j,i,policka);
            policka_buf->append(policko);
            //connect(policko->widget, SIGNAL(), policko->widget, SLOT());
            ui->fields->addWidget(policko,i,j,1,1);
        }

        policka->append(*policka_buf);

    }
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
