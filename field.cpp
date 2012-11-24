#include <QtGui>
#include "field.h"


Field::Field(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    QWidget(parent)
{
    vbox = new QVBoxLayout();
    vbox->setMargin(0);

    this->setMaximumWidth(50);
    this->setMaximumHeight(50);
    this->setLayout(vbox);

    xpos = x;
    ypos = y;

    policka = fields;
}

int Field::state = HORIZONTAL;




Field * Field::polickaAt(int x,int y)
{
    return policka->at(y)[x];
}
