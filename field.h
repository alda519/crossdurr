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
    QLineEdit * edit; // tady je pismenko
    QVBoxLayout * vbox; // layout ve widgetu policka
    int xpos, ypos; // pozice tohoto policka v matici policek
    QVector< QVector<Field *> > * policka; // pointer na layout vsech policek
    Field * polickaAt(int x,int y);

signals:

public slots:

protected:
    bool eventFilter(QObject *watched, QEvent * e);
};

enum { HORIZONTAL, VERTICAL };

#endif // FIELD_H
