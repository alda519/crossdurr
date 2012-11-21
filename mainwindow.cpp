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
        for (int j = 0; j<5; ++j)
        {
            Field * policko = new Field();
            //connect(policko->widget, SIGNAL(), policko->widget, SLOT());
            ui->fields->addWidget(policko->widget,i,j,1,1);
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
