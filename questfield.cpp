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
    editTE->setText("NEJAKY TEZKY UKOL");
    editTE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editTE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editTE->installEventFilter(this);
    editTE->setReadOnly(true);

    if(x != 0 || y != 0)
        vbox->addWidget(edit);

    type = QUESTFIELD;
}

bool QuestField::eventFilter(QObject *watched, QEvent *e)
{
    Q_UNUSED(watched);
    bool filtered = false;
    if(e->type() == QEvent::FocusIn) {
        qDebug() << "Focus QuestField " << xpos << "x" << ypos;
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
    }
    return filtered;
}
