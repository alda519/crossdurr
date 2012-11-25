#include <QtGui>
#include "questfield.h"
#include "field.h"

QuestField::QuestField(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    Field(x, y, fields, parent)
{
    QFont * f = new QFont();
    f->setPointSize(7);
    editTE = new QTextEdit();
    edit = editTE;
    editTE->setFont(*f);
    editTE->setText("NEJAKY BLBY TEXT");
    editTE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editTE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editTE->setContextMenuPolicy(Qt::PreventContextMenu);
    editTE->installEventFilter(this);
    editTE->setReadOnly(true);

    if(x != 0 || y != 0) {
        vbox->addWidget(edit);
        type = QUESTFIELD;
        baseStyle = new QString("background-color: #ccccff;");
        edit->setStyleSheet(*baseStyle);
    }
}


bool QuestField::decorate(bool force)
{
    if(force)
        edit->setStyleSheet("background-color: #ffcccc;");
    return false;
}


void QuestField::setText(QString text)
{
    editTE->setText(text);
}

void QuestField::setRandomText()
{
    // hackity hack
    std::string pole[40] = {
        "sloni zub", "svazek klesti", "narez", "hnetat", "zesileny zapor", "druh pocitacoveho konektoru",
        "cast svu", "lezet anglicky", "carodejova zeme", "vytvoren", "ilona domacky", "model",
        "televizni kabelovy kanal", "amplituda", "kujny material", "sedivy", "osklivost", "chytat zver",
        "inicialy zpevacky vondrackove", "zasevany", "takove mnozstvi",
    };
    editTE->setText(QString(pole[rand()%20].c_str()).toUpper());
}

bool QuestField::eventFilter(QObject *watched, QEvent *e)
{
    Q_UNUSED(watched);
    bool filtered = false;

    if(e->type() == QEvent::FocusIn) {

        qDebug() << "Focus QuestField " << xpos << "x" << ypos;

        if(state == HORIZONTAL) {
            if((xpos < (policka->at(ypos).count()-1)) && policka->at(ypos)[xpos+1]->type != EDITFIELD)
                state = ! state;
            if(xpos == (policka->at(ypos).count()-1))
                state = ! state;
        } else if(state == VERTICAL) {
            if((ypos < (policka->count()-1)) && policka->at(ypos+1)[xpos]->type != EDITFIELD)
                state = ! state;
            if(ypos == (policka->count()-1))
                state = ! state;
        }
        highlight();
    }
    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;

        if ((k->key () == Qt::Key_Left) && (xpos != 0)) {
            policka->at(ypos)[xpos-1]->edit->setFocus();
        } else if ((k->key () == Qt::Key_Right) && (xpos < (policka->at(ypos).count()-1))) {
            policka->at(ypos)[xpos+1]->edit->setFocus();
        } else if ((k->key () == Qt::Key_Down) && (ypos < (policka->count()-1))) {
            policka->at(ypos+1)[xpos]->edit->setFocus();
        } else if ((k->key () == Qt::Key_Up) && (ypos != 0) ) {
            policka->at(ypos-1)[xpos]->edit->setFocus();
        } else if (k->key () == Qt::Key_Delete) {
            ;
        } else if(k->key () == Qt::Key_Return) {
            state = ! state;
            highlight();
        } else if(k->key() == Qt::Key_Home) {
            policka->at(ypos)[0]->edit->setFocus();
        } else if(k->key() == Qt::Key_End) {
            policka->at(ypos)[policka->at(ypos).count()-1]->edit->setFocus();
        } else if(k->key() == Qt::Key_PageUp) {
            policka->at(0)[xpos]->edit->setFocus();
        } else if(k->key() == Qt::Key_PageDown) {
            policka->at(policka->count()-1)[xpos]->edit->setFocus();
        } else if (k->key () == Qt::Key_Backspace) {
            if(state == HORIZONTAL && (xpos > 0)) {
                policka->at(ypos)[xpos-1]->edit->setFocus();
                if(policka->at(ypos)[xpos-1]->type == EDITFIELD)
                    policka->at(ypos)[xpos-1]->setText("");
            } else if(state == VERTICAL && (ypos > 0)) {
                policka->at(ypos-1)[xpos]->edit->setFocus();
                if(policka->at(ypos-1)[xpos]->type == EDITFIELD)
                    policka->at(ypos-1)[xpos]->setText("");
            }
        } else if (!(k->text().isEmpty()) && (k->key() != Qt::Key_Tab)) {
            // samo posunout na dalsi pismeno, pripadne slovo
            if(state == HORIZONTAL) {
                if (xpos < (policka->at(ypos).count()-1) && policka->at(ypos)[xpos+1]->type == EDITFIELD) {
                    if(k->key() == Qt::Key_Space)
                        policka->at(ypos)[xpos+1]->setText("");
                    else
                        policka->at(ypos)[xpos+1]->setText(k->text().toUpper());
                    if(xpos < (policka->at(ypos).count()-2))
                        policka->at(ypos)[xpos+2]->edit->setFocus();
                    else
                        policka->at(ypos)[xpos+1]->edit->setFocus();
                }
            } else if(state == VERTICAL) {
                if (ypos < (policka->count()-1) && policka->at(ypos+1)[xpos]->type == EDITFIELD) {
                    if(k->key() == Qt::Key_Space)
                        policka->at(ypos+1)[xpos]->setText("");
                    else
                        policka->at(ypos+1)[xpos]->setText(k->text().toUpper());
                    if(ypos < (policka->count()-2))
                        policka->at(ypos+2)[xpos]->edit->setFocus();
                    else
                        policka->at(ypos+1)[xpos]->edit->setFocus();
                }
            }
        }
    }
    return filtered;
}
