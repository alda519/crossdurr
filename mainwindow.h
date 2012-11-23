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
    
private:
    Ui::MainWindow *ui;
    int krizovkaWidth, krizovkaHeight;

public slots:
    void otevriKrizovku();
    void novaKrizovka();
};

#endif // MAINWINDOW_H
