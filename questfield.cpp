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


bool QuestField::eventFilter(QObject *watched, QEvent *e)
{
    Q_UNUSED(watched);
    bool filtered = false;

    if(e->type() == QEvent::FocusIn) {
        highlight();
        qDebug() << "Focus QuestField " << xpos << "x" << ypos;
    /*
        if(state == HORIZONTAL) {
            if((xpos < (policka->at(ypos).count()-1)) && policka->at(ypos)[xpos+1]->type == EDITFIELD)
                ((QLineEdit *)(policka->at(ypos)[xpos+1]->edit))->setFocus();
            else if((ypos < (policka->count()-1)) && policka->at(ypos+1)[xpos]->type == EDITFIELD) {
                state = ! state;
                ((QLineEdit *)(policka->at(ypos+1)[xpos]->edit))->setFocus();
            }
        } else if(state == VERTICAL) {
            if((ypos < (policka->count()-1)) && policka->at(ypos+1)[xpos]->type == EDITFIELD)
                ((QLineEdit *)(policka->at(ypos+1)[xpos]->edit))->setFocus();
             else if((xpos < (policka->at(ypos).count()-1)) && policka->at(ypos)[xpos+1]->type == EDITFIELD) {
                state = ! state;
                ((QLineEdit *)(policka->at(ypos)[xpos+1]->edit))->setFocus();
            }
        }
    */
        // TODO kdyz chytne highlight ve smeru, kde to nejde, tak by se mel preklopit
    }
    if (e->type () == QEvent::KeyPress)
    {
        QKeyEvent* k = (QKeyEvent*) e;
        if(k->key () == Qt::Key_Return) {
            state = ! state;
            highlight();
        }
        // TODO
        //  kdyz se napise pismeno, tak se umisti ve smeru state a focus poskoci o 2 jinak se focus nebude predavat nikde
        // tzn sipky maji fungovat
        // pismenka maj fungovat
    }
    return filtered;
}