#include "editfield.h"

EditField::EditField(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    Field(x, y, fields, parent)
{
    editLE = new QLineEdit();
    edit = editLE;
    editLE->installEventFilter(this);
    editLE->setMaximumWidth(50);
    editLE->setMaximumHeight(50);
    editLE->setText("");
    editLE->setReadOnly(true);
    editLE->setContextMenuPolicy(Qt::PreventContextMenu);
    editLE->setStyleSheet( "color:black; background-color:white" );

    editLE->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    editLE->setMaxLength(1);

    QFont * f = new QFont();
    f->setPointSize(25);
    edit->setFont(*f);

    if(x != 0 || y != 0)
        vbox->addWidget(edit);

    type = EDITFIELD;
}

bool EditField::decorate(bool force)
{
    Q_UNUSED(force);
    edit->setStyleSheet("border: 1px solid red");
    return true;
}

void EditField::setText(QString text)
{
    editLE->setText(text);
}

void EditField::setRandomText()
{
    char x = rand() % 26 + 'A';
    if(editLE->text().length() == 0)
        editLE->setText(QString::fromAscii(&x, 1));
}


bool EditField::eventFilter(QObject *watched, QEvent *e)
{
    Q_UNUSED(watched);
    bool filtered = false;
    if(e->type() == QEvent::FocusIn) {
        qDebug() << "Focus EditField " << xpos << "x" << ypos;

        if (*aktualniNastroj!= UNKNOWNFIELD)
            changeFieldType(*aktualniNastroj);
        else
            highlight();
        filtered = true;
    }

    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;

        // doleva
        if ((k->key () == Qt::Key_Left) && (xpos != 0)) {
            policka->at(ypos)[xpos-1]->edit->setFocus();
        }

        // doprava
        else if ((k->key () == Qt::Key_Right) && (xpos < (policka->at(ypos).count()-1))) {
            policka->at(ypos)[xpos+1]->edit->setFocus();
        }

        // dolu
        else if ((k->key () == Qt::Key_Down) && (ypos < (policka->count()-1))) {
            policka->at(ypos+1)[xpos]->edit->setFocus();
        }

        // nahoru
        else if ((k->key () == Qt::Key_Up) && (ypos != 0) ) {
            policka->at(ypos-1)[xpos]->edit->setFocus();
        }

        // preklopeni horizont./vertikal.
        else if(k->key () == Qt::Key_Return) {
            state = ! state;
            highlight();
        }

        else if (k->key () == Qt::Key_Delete)
            editLE->setText("");

        // home end atd. se muze hodit
        else if(k->key() == Qt::Key_Home) {
            qDebug() << "HOME";
            policka->at(ypos)[0]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_End) {
            policka->at(ypos)[policka->at(ypos).count()-1]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_PageUp) {
            policka->at(0)[xpos]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_PageDown) {
            policka->at(policka->count()-1)[xpos]->edit->setFocus();
        }
        else if(k->key() == Qt::Key_Space) {
            editLE->setText("");
            if(state == HORIZONTAL && (xpos < (policka->at(ypos).count()-1)))
                policka->at(ypos)[xpos+1]->edit->setFocus();
            else if(state == VERTICAL && (ypos < (policka->count()-1)))
                policka->at(ypos+1)[xpos]->edit->setFocus();
        }

        // backspace smaze predchozi znak a da na nej focus
        else if (k->key () == Qt::Key_Backspace) {
            if(state == HORIZONTAL && (xpos > 0)) {
                policka->at(ypos)[xpos-1]->edit->setFocus();
                if(policka->at(ypos)[xpos-1]->type == EDITFIELD)
                    ((QLineEdit *)(policka->at(ypos)[xpos-1]->edit))->setText("");
            } else if(state == VERTICAL && (ypos > 0)) {
                policka->at(ypos-1)[xpos]->edit->setFocus();
                if(policka->at(ypos-1)[xpos]->type == EDITFIELD)
                    ((QLineEdit *)(policka->at(ypos-1)[xpos]->edit))->setText("");
            }
        }

        // napsani pismene
        else if (!(k->text().isEmpty()) && (k->key() != Qt::Key_Tab)) {
            editLE->setText(k->text().toUpper());
            // samo posunout na dalsi pismeno, pripadne slovo
            if(state == HORIZONTAL) {
                if (xpos < (policka->at(ypos).count()-1)) {
                    policka->at(ypos)[xpos+1]->edit->setFocus();
                }
            } else if(state == VERTICAL) {
                if (ypos < (policka->count()-1)) {
                    policka->at(ypos+1)[xpos]->edit->setFocus();
                }
            }
        }

        qDebug() << k->text();

        filtered = true;//eat event
    }
    return filtered & false;
}
