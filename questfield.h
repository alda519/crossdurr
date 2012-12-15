#ifndef QUESTFIELD_H
#define QUESTFIELD_H

#include "field.h"

class QuestField : public Field
{
public:
    QuestField(int x, int y, QVector<QVector<Field *> > *fields, QWidget *parent = 0);
    PolickoZadani * editTE;

    bool decorate(bool force);
    void setText(QString text);
    void setRandomText();

signals:

public slots:

protected:
    bool eventFilter(QObject *watched, QEvent * e);
};

#endif // QUESTFIELD_H
