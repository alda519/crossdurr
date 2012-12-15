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

    void vytvorVytvareciListu();
    void vytvorLusticiListu();
    
private:
    Ui::MainWindow *ui;
    int krizovkaWidth, krizovkaHeight;
    QLineEdit * kSirka, * kVyska;
    QTextEdit * tAjenka;

    // tlacitka s modama
    QToolBar * tools;
    QActionGroup *actTools;
    QAction *actEdit;
    QAction *actTajenka;
    QAction *actSymbol;
    QAction *actQuest;
    void createActions();


public slots:
    void otevriKrizovku();
    void novaKrizovka();
    void vyplnitNesmyslama();
    void zobrazVytvareciListu();
    void zobrazLusticiListu();

    void selectEdit();
    void selectTajenka();
    void selectSymbol();
    void selectQuest();

};

#endif // MAINWINDOW_H
