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

    type = UNKNOWNFIELD;
    baseStyle = new QString("");
}

int Field::state = HORIZONTAL;




Field * Field::polickaAt(int x,int y)
{
    return policka->at(y)[x];
}

void Field::setBaseStyleSheet()
{
    edit->setStyleSheet(* baseStyle);
}


void Field::highlight()
{
    // smazani stylu
    for(int i = 0; i < (policka->at(ypos).count()); ++i)
        for(int j = 0; j < (policka->count()); ++j)
            if(policka->at(j)[i]->type != UNKNOWNFIELD)
               policka->at(j)[i]->setBaseStyleSheet();

    // zvyrazneni radku / TODO sloupce
    if(state == HORIZONTAL) { // radek / sloupec
        for(int i = xpos; i >= 0 && policka->at(ypos)[i]->decorate(); --i) ;
        for(int i = xpos+1; i < (policka->at(ypos).count()) && policka->at(ypos)[i]->decorate(false); ++i) ;
    } else {
        for(int i = ypos; i >= 0 && policka->at(i)[xpos]->decorate(); --i) ;
        for(int i = ypos+1; i < (policka->count()) && policka->at(i)[xpos]->decorate(false); ++i) ;
    }

    // zvyrazneni policka
    if(policka->at(ypos)[xpos]->type == QUESTFIELD)
        policka->at(ypos)[xpos]->edit->setStyleSheet("background-color: #ffcccc;");
    else if(policka->at(ypos)[xpos]->type == EDITFIELD)
        policka->at(ypos)[xpos]->edit->setStyleSheet("border: 3px solid red");
}


bool Field::decorate(bool force)
{
    Q_UNUSED(force);
    qDebug() << "Tohle se nema nikdy stat";
    return false;
}

void Field::setText(QString text)
{
    Q_UNUSED(text);
    qDebug() << "Tohle se nema nikdy stat";
}

void Field::setRandomText()
{
    qDebug() << "Tohle se nema nikdy stat";
}
