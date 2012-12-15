#ifndef TAJENKAFIELD_H
#define TAJENKAFIELD_H

#include "editfield.h"

class tajenkaField : public EditField
{
public:
    tajenkaField(int x, int y, QVector<QVector<Field *> > *fields, QWidget *parent = 0);
    bool decorate(bool force = true);
    void setBaseStyleSheet();

    QString * baseStyle;
};

#endif // TAJENKAFIELD_H
