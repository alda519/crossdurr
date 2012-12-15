#ifndef SYMBOLFIELD_H
#define SYMBOLFIELD_H

#include "field.h"

class SymbolField : public Field
{
public:
    SymbolField(int x, int y, QVector<QVector<Field *> > *fields, QWidget *parent = 0);
    PolickoPismenko * editLE;

    bool decorate(bool force = true);
    void setText(QString text = "");
    void setRandomText();

protected:
    bool eventFilter(QObject *watched, QEvent * e);


};

#endif // SYMBOLFIELD_H
