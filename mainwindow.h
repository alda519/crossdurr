#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <field.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    QVector< QVector<Field *> > * policka;
    ~MainWindow();

    QVBoxLayout *listaVytvareni;            // bocni lista vlevo co se zobrazuje pri vytvareni krizvoky
    QVBoxLayout *listaLusteni;              // bocni lista vlevo co se zobrazuje pri lusteni krizovky
    int* aktualniNastroj;

    void vytvorVytvareciListu();
    void vytvorLusticiListu();
    void smazWidget(int x,int y);

    enum { OZNACOVANI, EDITFIELD, QUESTFIELD, TAJENKAFIELD, SYMBOLFIELD} ;
    
private:
    Ui::MainWindow *ui;
    int krizovkaWidth, krizovkaHeight;

    // veci z listy vlevo
    QLineEdit * kSirka, * kVyska;
    QTextEdit * tAjenka;
    QRadioButton *radioPismeno;
    QRadioButton *radioTajenka;
    QRadioButton *radioSymbol;
    QRadioButton *radioZadani;
    QRadioButton *radioOznacovani;


public slots:
    void otevriKrizovku();
    void ulozKrizovku();
    void novaKrizovka();
    void vyplnitNesmyslama();
    void zobrazVytvareciListu();
    void zobrazLusticiListu();

    void umistitTajenku();

    void nastavNastrojPismeno();
    void nastavNastrojTajenka();
    void nastavNastrojZadani();
    void nastavNastrojSymbol();
    void nastavNastrojOznacovani();


};

#endif // MAINWINDOW_H
