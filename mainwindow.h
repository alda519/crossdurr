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


public slots:
    void otevriKrizovku();
};

#endif // MAINWINDOW_H
