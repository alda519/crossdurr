#ifndef OTEVRI_H
#define OTEVRI_H

#include <QDialog>

namespace Ui {
class Otevri;
}

class Otevri : public QDialog
{
    Q_OBJECT
    
public:
    explicit Otevri(QWidget *parent = 0);
    ~Otevri();
    
private:
    Ui::Otevri *ui;
};

#endif // OTEVRI_H
