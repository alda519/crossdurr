#include <QtGui>
#include "field.h"


Field::Field(QWidget *parent) :
    QWidget(parent)
{
    vbox = new QVBoxLayout();

    widget = new QWidget();
    widget->setMaximumWidth(50);
    widget->setMaximumHeight(50);
    edit = new QLineEdit();
    edit->setMaximumWidth(50);
    edit->setMaximumHeight(50);
    edit->setText("aa");

    vbox->addWidget(edit);
    widget->setLayout(vbox);
}
