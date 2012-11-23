#include <QtGui>
#include "field.h"


Field::Field(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    QWidget(parent)
{
    edit = new QLineEdit();
    edit->installEventFilter(this);
    edit->setMaximumWidth(50);
    edit->setMaximumHeight(50);
    edit->setText("");
    edit->setReadOnly(true);
    edit->setContextMenuPolicy(Qt::PreventContextMenu);
    edit->setStyleSheet( "color:black; background-color:white" );

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
    static int state = HORIZONTAL;

    bool filtered = false;
    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;
        int newx = -1, newy = -1;

        // doleva
        if ((k->key () == Qt::Key_Left) && (xpos != 0)) {
            policka->at(ypos)[xpos-1]->edit->setFocus();
            newy = ypos;
            newx = xpos-1;
        }

        // doprava
        else if ((k->key () == Qt::Key_Right) && (xpos < (policka->at(ypos).count()-1))) {
            policka->at(ypos)[xpos+1]->edit->setFocus();
            newy = ypos;
            newx = xpos+1;
        }

        // dolu
        else if ((k->key () == Qt::Key_Down) && (ypos < (policka->count()-1))) {
            policka->at(ypos+1)[xpos]->edit->setFocus();
            newy = ypos+1;
            newx = xpos;
        }

        // nahoru
        else if ((k->key () == Qt::Key_Up) && (ypos != 0) ) {
            policka->at(ypos-1)[xpos]->edit->setFocus();
            newy = ypos-1;
            newx = xpos;
        }

        // preklopeni horizont./vertikal.
        else if(k->key () == Qt::Key_Return) {
            state = ! state;
            newx = xpos;
            newy = ypos;
        }

        else if (k->key () == Qt::Key_Delete)
            edit->setText("");

        // home end atd. se muze hodit
        else if(k->key() == Qt::Key_Home) {
            newy = ypos;
            newx = 0;
            policka->at(newy)[newx]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_End) {
            newy = ypos;
            newx = policka->at(ypos).count()-1;
            policka->at(newy)[newx]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_PageUp) {
            newy = 0;
            newx = xpos;
            policka->at(newy)[newx]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_PageDown) {
            newy = policka->count()-1;
            newx = xpos;
            policka->at(newy)[newx]->edit->setFocus();
        }

        // backspace smaze predchozi znak a da na nej focus
        else if (k->key () == Qt::Key_Backspace) {
            if(state == HORIZONTAL && (xpos > 0)) {
                policka->at(ypos)[xpos-1]->edit->setFocus();
                newy = ypos;
                newx = xpos-1;
                policka->at(ypos)[xpos-1]->edit->setText("");
            } else if(state == VERTICAL && (ypos > 0)) {
                policka->at(ypos-1)[xpos]->edit->setFocus();
                newy = ypos-1;
                newx = xpos;
                policka->at(ypos-1)[xpos]->edit->setText("");
            }
        }

        // napsani pismene
        else if (!(k->text().isEmpty()) && (k->key() != Qt::Key_Tab)) {
            edit->setText(k->text().toUpper());
            // samo posunout na dalsi pismeno, pripadne slovo
            if(state == HORIZONTAL) {
                if (xpos < (policka->at(ypos).count()-1)) {
                    policka->at(ypos)[xpos+1]->edit->setFocus();
                    newy = ypos;
                    newx = xpos+1;
                } else if((ypos < (policka->count()-1))) {
                    policka->at(ypos+1)[0]->edit->setFocus();
                    newy = ypos+1;
                    newx = 0;
                }
            } else if(state == VERTICAL) {
                if (ypos < (policka->count()-1)) {
                    policka->at(ypos+1)[xpos]->edit->setFocus();
                    newy = ypos+1;
                    newx = xpos;
                } else if (xpos < (policka->at(ypos).count()-1)) {
                    policka->at(0)[xpos+1]->edit->setFocus();
                    newy = 0;
                    newx = xpos+1;
                }
            }
        }

        //qDebug() << "left" << xpos << polickaAt(xpos,ypos)->edit->text();
        qDebug() << k->text();

        // vyreseni stylovani tech policekr
        if(newx != -1 && newy != -1) {
            // smazani stylu
            for(int i = 0; i < (policka->at(ypos).count()); ++i)
                for(int j = 0; j < (policka->count()); ++j)
                    policka->at(j)[i]->edit->setStyleSheet("");

            // zvyrazneni radku / TODO sloupce
            if(state == HORIZONTAL) { // radek / sloupec
                for(int i = 0; i < (policka->at(ypos).count()); ++i)
                    policka->at(newy)[i]->edit->setStyleSheet("border: 1px solid red");
            } else {
                for(int i = 0; i < (policka->count()); ++i)
                    policka->at(i)[newx]->edit->setStyleSheet("border: 1px solid red");
            }
            // zvyrazneni policka
            policka->at(newy)[newx]->edit->setStyleSheet("border: 3px solid red");
        }

        filtered = true;//eat event
        //}
    }
    return filtered & false;
}


Field * Field::polickaAt(int x,int y)
{
    return policka->at(y)[x];
}
