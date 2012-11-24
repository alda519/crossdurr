#ifndef EDITFIELD_H
#define EDITFIELD_H

#include "field.h"

class EditField : public Field
{
public:
    EditField(int x, int y, QVector<QVector<Field *> > *fields, QWidget *parent = 0);
    QLineEdit * editLE;

protected:
    bool eventFilter(QObject *watched, QEvent * e);

private:
    void highlight();
};

#endif // EDITFIELD_H
