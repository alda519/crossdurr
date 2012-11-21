#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(QWidget *parent = 0);
    QWidget * widget;
    QLineEdit * edit;
    QVBoxLayout * vbox;

signals:

public slots:

protected:
    bool eventFilter(QObject *watched, QEvent * e);
};

#endif // FIELD_H
