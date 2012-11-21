#include <QtGui>
#include "field.h"


Field::Field(QWidget *parent) :
    QWidget(parent)
{
    vbox = new QVBoxLayout();
    vbox->setMargin(0);

    widget = new QWidget();
    widget->setMaximumWidth(50);
    widget->setMaximumHeight(50);

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

    vbox->addWidget(edit);
    widget->setLayout(vbox);
}

bool Field::eventFilter(QObject *watched, QEvent *e)
{
    static int x;
    bool filtered = false;
    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;
        if (k->key () == Qt::Key_Delete)
            edit->setText("");
        //if(k->key() >= Qt::Key_A && k->key() <= Qt::Key_Z) {
            edit->setText(k->text().toUpper());
        qDebug() << k->text();
            filtered = true;//eat event
        //}
    }
    return filtered & false;
}
