#include "symbolfield.h"

SymbolField::SymbolField(int x, int y, QVector< QVector<Field *> > * fields, QWidget *parent) :
    Field(x, y, fields, parent)
{
    editLE = new PolickoPismenko(this);
    edit = editLE;
    editLE->installEventFilter(this);
    editLE->setMouseTracking(true);
    editLE->setMaximumWidth(50);
    editLE->setMaximumHeight(50);
    editLE->setText("*");
    editLE->setReadOnly(true);
    editLE->setContextMenuPolicy(Qt::PreventContextMenu);
    editLE->setStyleSheet( "color:black; background-color: #ccccff;" );

    editLE->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    editLE->setMaxLength(1);

    QFont * f = new QFont();
    f->setPointSize(25);
    edit->setFont(*f);

    baseStyle = new QString("background-color: #ccccff;");
    edit->setStyleSheet(*baseStyle);
    vbox->addWidget(edit);


    type = SYMBOLFIELD;
}

bool SymbolField::decorate(bool force)
{
    if(force)
        edit->setStyleSheet("background-color: #ffcccc;");
    return false;
}

void SymbolField::setText(QString text)
{
    editLE->setText(text);
}

void SymbolField::setRandomText()
{
    //
}


bool SymbolField::eventFilter(QObject *watched, QEvent *e)
{
    Q_UNUSED(watched);
    bool filtered = false;
    if(e->type() == QEvent::FocusIn) {
        qDebug() << "Focus SymbolField " << xpos << "x" << ypos;
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
    return filtered & false;
}

