#include "otevri.h"
#include "ui_otevri.h"

Otevri::Otevri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Otevri)
{
    ui->setupUi(this);
}

Otevri::~Otevri()
{
    delete ui;
}
