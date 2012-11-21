#include <QtGui>
#include "field.h"


Field::Field(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    QWidget(parent)
{
    edit = new QLineEdit();
    edit->installEventFilter(this);
    edit->setMaximumWidth(50);
    edit->setMaximumHeight(50);
    edit->setText("aa");
    edit->setReadOnly(true);

    edit->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    //edit->setInputMask(">");
    edit->setMaxLength(1);

    QFont * f = new QFont();
    f->setPointSize(25);
    edit->setFont(*f);


    vbox = new QVBoxLayout();
    vbox->setMargin(0);
    vbox->addWidget(edit);

    this->setMaximumWidth(50);
    this->setMaximumHeight(50);
    this->setLayout(vbox);

    xpos = x;
    ypos = y;

    policka = fields;
}

bool Field::eventFilter(QObject *watched, QEvent *e)
{
    static int x;
    bool filtered = false;
    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;


        // doleva
        if ((k->key () == Qt::Key_Left) && (xpos != 0))
            policka->at(ypos)[xpos-1]->edit->setFocus();

        // doprava
        else if ((k->key () == Qt::Key_Right) && (xpos < (policka->at(ypos).count()-1)))
            policka->at(ypos)[xpos+1]->edit->setFocus();

        // dolu
        else if ((k->key () == Qt::Key_Down) && (ypos < (policka->count()-1)))
            policka->at(ypos+1)[xpos]->edit->setFocus();

        // nahoru
        else if ((k->key () == Qt::Key_Up) && (ypos != 0) )
            policka->at(ypos-1)[xpos]->edit->setFocus();

        //qDebug() << "left" << xpos << policka->at(ypos)[xpos]->edit->text();

        else if (k->key () == Qt::Key_Delete)
            edit->setText("");
        //if(k->key() >= Qt::Key_A && k->key() <= Qt::Key_Z) {
        else
            edit->setText(k->text().toUpper());
        qDebug() << k->text();
            filtered = true;//eat event
        //}
    }
    return filtered & false;
}
