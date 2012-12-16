#include "tajenkafield.h"

tajenkaField::tajenkaField(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    EditField(x, y, fields, parent)

{
    type = TAJENKAFIELD;

    baseStyle = new QString("color:black; background-color:yellow; border-width: 1px; border-style: solid; border-radius: 4px; border-color: rgb(196,193,189);");
    editLE->setStyleSheet( *baseStyle );
}

bool tajenkaField::decorate(bool force)
{
    Q_UNUSED(force);
    edit->setStyleSheet("border: 1px solid red; background-color:yellow;");
    return true;
}

void tajenkaField::setBaseStyleSheet()
{
    edit->setStyleSheet(* baseStyle);    
}
