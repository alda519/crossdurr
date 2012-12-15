#include "tajenkafield.h"

tajenkaField::tajenkaField(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    EditField(x, y, fields, parent)

{
    editLE->setStyleSheet( "color:black; background-color:yellow" );
    type = TAJENKAFIELD;

    baseStyle = new QString;
    *baseStyle = "color:black; background-color:yellow";
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
