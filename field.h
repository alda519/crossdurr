#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent = 0);
    QWidget * edit; // tady je pismenko
    QVBoxLayout * vbox; // layout ve widgetu policka
    int xpos, ypos; // pozice tohoto policka v matici policek
    QVector< QVector<Field *> > * policka; // pointer na layout vsech policek
    Field * polickaAt(int x,int y);

    static int state;
    int type;

signals:

public slots:

};

enum { HORIZONTAL, VERTICAL };

enum { UNKNOWNFIELD, EDITFIELD, QUESTFIELD } ;

#endif // FIELD_H
