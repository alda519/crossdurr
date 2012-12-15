#include <QtGui>
#include "field.h"
#include "editfield.h"
#include "questfield.h"
#include "tajenkafield.h"
#include "symbolfield.h"

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
    else if (policka->at(ypos)[xpos]->type == EDITFIELD)
        policka->at(ypos)[xpos]->edit->setStyleSheet("border: 3px solid red");
    else if (policka->at(ypos)[xpos]->type == TAJENKAFIELD)
        policka->at(ypos)[xpos]->edit->setStyleSheet("border: 3px solid red; background-color:yellow;");
    else if (policka->at(ypos)[xpos]->type == SYMBOLFIELD)
        policka->at(ypos)[xpos]->edit->setStyleSheet("background-color: #ffcccc;");
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

void Field::changeFieldType(int newType)
{
    if (type != newType)
    {
        Field *newField;
        switch (newType)
        {
        case EDITFIELD:
            newField = new EditField(xpos,ypos,policka);
            break;
        case QUESTFIELD:
            newField = new QuestField(xpos,ypos,policka);
            break;
        case TAJENKAFIELD:
            newField = new tajenkaField(xpos,ypos,policka);
            break;
        case SYMBOLFIELD:
            newField = new SymbolField(xpos,ypos,policka);
            break;
        case UNKNOWNFIELD:
            return;
        default:
            qDebug() << "Tohle se nema nikdy stat";
            return;
        }

        newField->mrizka = mrizka;
        newField->aktualniNastroj = aktualniNastroj;

        // da se pryc stary widget a na jeho misto prijde novy
        mrizka->removeWidget(mrizka->itemAtPosition(ypos,xpos)->widget());
        mrizka->addWidget(newField,ypos,xpos,1,1);

        // a jeste se prohodi stary s novym v matici policek
        (*policka)[ypos].replace(xpos,newField);

        // chtelo by to neco jako toto, jinak to bude celkem slusne leakovat
        //delete this;

    }
}


PolickoZadani::PolickoZadani(Field * pPolicko): policko(pPolicko) {}

void PolickoZadani::mousePressEvent(QMouseEvent *)
{
    qDebug() << "mouse click";
    if (*(policko->aktualniNastroj)!= UNKNOWNFIELD)
        policko->changeFieldType(*(policko->aktualniNastroj));
}

void PolickoZadani::mouseDoubleClickEvent(QMouseEvent *)
{
    setReadOnly(false);
    removeEventFilter(policko);
}

void PolickoZadani::focusOutEvent(QFocusEvent *e)
{
    setReadOnly(true);
    installEventFilter(policko);
}

PolickoPismenko::PolickoPismenko(Field * pPolicko): policko(pPolicko) {}

void PolickoPismenko::mousePressEvent(QMouseEvent *)
{
    qDebug() << "mouse click";
    if (*(policko->aktualniNastroj)!= UNKNOWNFIELD)
        policko->changeFieldType(*(policko->aktualniNastroj));
}

void PolickoPismenko::mouseDoubleClickEvent(QMouseEvent *)
{
    qDebug() << "mouse double click";
}
