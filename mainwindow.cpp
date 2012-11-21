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

    for (int i = 0; i<5; ++i)
    {
        Field * policko = new Field();
        ui->fields->addWidget(policko->widget,1,i,1,1);
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
