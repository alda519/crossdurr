#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include "questfield.h"
#include "editfield.h"
#include "tajenkafield.h"
#include "symbolfield.h"
#include <QString>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionKonec,SIGNAL(activated()), this, SLOT(close()));
    connect(ui->actionOtev_t, SIGNAL(activated()), this, SLOT(otevriKrizovku()));
    connect(ui->actionUlo_it, SIGNAL(activated()), this, SLOT(ulozKrizovku()));

    krizovkaWidth = 0;
    krizovkaHeight = 0;

    //setMinimumSize(40 + 160 + 5 * 52, 250 + 5 * 52);
    //setMaximumSize(40 + 160 + 5 * 52, 250 + 5 * 52);

    vytvorLusticiListu();
    vytvorVytvareciListu();

    ui->widgetVytvareni->setLayout(listaVytvareni);
    ui->widgetLusteni->setLayout(listaLusteni);

    zobrazVytvareciListu();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * menu vlevo naboku, zobrazuje se jenom pri vytvareni krizovky
 */
void MainWindow::vytvorVytvareciListu()
{

    listaVytvareni = new QVBoxLayout;
      // nastaveni velikosti
    listaVytvareni->addWidget(new QLabel("Sirka:"));
    kSirka = new QLineEdit("15");
    kVyska = new QLineEdit("10");
    listaVytvareni->addWidget(kSirka);
    listaVytvareni->addWidget(new QLabel("Vyska:"));
    listaVytvareni->addWidget(kVyska);
    QPushButton * newKrizovkaBtn = new QPushButton(QString("Nastavit velikost"));
    listaVytvareni->addWidget(newKrizovkaBtn);
      // tajenka
    listaVytvareni->addWidget(new QLabel("Tajenka:"));
    tAjenka = new QTextEdit("DESNE SUPER TAJENKA");
    tAjenka->setMaximumWidth(160);
    tAjenka->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    listaVytvareni->addWidget(tAjenka);

    QPushButton *umistiTajenkuBtn = new QPushButton(QString("Umistit tajenku"));
    listaVytvareni->addWidget(umistiTajenkuBtn);

    // nastrojovy menu
    listaVytvareni->addWidget(new QLabel("Nastroje:"));
    radioPismeno = new QRadioButton("Pismeno");
    radioTajenka = new QRadioButton("Tajenka");
    radioSymbol = new QRadioButton("Symbol");
    radioZadani = new QRadioButton("Zadani");
    radioOznacovani = new QRadioButton("Oznacovani");
    listaVytvareni->addWidget(radioPismeno);
    listaVytvareni->addWidget(radioTajenka);
    listaVytvareni->addWidget(radioSymbol);
    listaVytvareni->addWidget(radioZadani);
    listaVytvareni->addWidget(radioOznacovani);

    connect(radioPismeno, SIGNAL(pressed()), this, SLOT(nastavNastrojPismeno()));
    connect(radioTajenka, SIGNAL(pressed()), this, SLOT(nastavNastrojTajenka()));
    connect(radioSymbol, SIGNAL(pressed()), this, SLOT(nastavNastrojSymbol()));
    connect(radioZadani, SIGNAL(pressed()), this, SLOT(nastavNastrojZadani()));
    connect(radioOznacovani, SIGNAL(pressed()), this, SLOT(nastavNastrojOznacovani()));


    radioPismeno->setStyleSheet(" QRadioButton::indicator::unchecked {image: url(:/images/pismeno.png);} \
                                QRadioButton::indicator::checked {image: url(:/images/pismeno.png);} ");

    radioTajenka->setStyleSheet(" QRadioButton::indicator::unchecked {image: url(:/images/tajenka.png);} \
                                QRadioButton::indicator::checked {image: url(:/images/tajenka.png);}");

    radioSymbol->setStyleSheet(" QRadioButton::indicator::unchecked {image: url(:/images/symbol.png);} \
                                QRadioButton::indicator::checked {image: url(:/images/symbol.png);}");

    radioZadani->setStyleSheet(" QRadioButton::indicator::unchecked {image: url(:/images/slovo.png);} \
                                QRadioButton::indicator::checked {image: url(:/images/slovo.png);}");

    radioOznacovani->setStyleSheet(" QRadioButton::indicator::unchecked {image: url(:/images/kurzor.png);} \
                                QRadioButton::indicator::checked {image: url(:/images/kurzor.png);}");


    setStyleSheet("QRadioButton::checked {border: 2px solid #8f8f91;} \
    QRadioButton { \
         border-radius: 6px; \
         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
                                           stop: 0 #f6f7fa, stop: 1 #dadbde);} \
    ");


               //QRadioButton::indicator { width: 25px; height: 25px;} \

    aktualniNastroj = new int;
    *aktualniNastroj = OZNACOVANI;
    radioOznacovani->setChecked(true);

      // cervene tlacitko
    QPushButton * finishBtn = new QPushButton("Doplnit prazdne");
    finishBtn->setStyleSheet("background-color: #ff3333;");
    listaVytvareni->addWidget(finishBtn);

    QPushButton * lustitBtn = new QPushButton("Lustit");
    lustitBtn->setStyleSheet("background-color: #ff3333;");
    listaVytvareni->addWidget(lustitBtn);

    connect(newKrizovkaBtn, SIGNAL(pressed()), this, SLOT(novaKrizovka()));
    connect(finishBtn, SIGNAL(pressed()), this, SLOT(vyplnitNesmyslama()));
    connect(lustitBtn, SIGNAL(pressed()), this, SLOT(zobrazLusticiListu()));
    connect(umistiTajenkuBtn, SIGNAL(pressed()), this, SLOT(umistitTajenku()));

}

/*
 * menu vlevo naboku, zobrazuje se jenom pri lusteni
 */
void MainWindow::vytvorLusticiListu()
{
    listaLusteni = new QVBoxLayout;

    // napovedy
    listaLusteni->addWidget(new QLabel("Napovedy"));
    QTextEdit *napovedy = new QTextEdit("ITU ITO IZU IPZ UNP INC IMP");
    napovedy->setMaximumWidth(160);
    napovedy->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    listaLusteni->addWidget(napovedy);

    // tajenka
    listaLusteni->addWidget(new QLabel("Kontext Tajenky"));
    tAjenka = new QTextEdit("DESNE SUPER TAJENKA");
    tAjenka->setMaximumWidth(160);
    tAjenka->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    listaLusteni->addWidget(tAjenka);

    QPushButton * editorBtn = new QPushButton("Zpet do editoru");
    editorBtn->setStyleSheet("background-color: #ff3333;");
    listaLusteni->addWidget(editorBtn);
    connect(editorBtn, SIGNAL(pressed()), this, SLOT(zobrazVytvareciListu()));

}

void MainWindow::zobrazVytvareciListu()
{
    ui->widgetVytvareni->setVisible(true);
    ui->widgetLusteni->setVisible(false);
}

void MainWindow::zobrazLusticiListu()
{
    ui->widgetVytvareni->setVisible(false);
    ui->widgetLusteni->setVisible(true);

}

void MainWindow::umistitTajenku()
{
    // doplnit
}

void MainWindow::nastavNastrojPismeno()
{
    *aktualniNastroj = EDITFIELD;
}

void MainWindow::nastavNastrojTajenka()
{
    *aktualniNastroj = TAJENKAFIELD;
}

void MainWindow::nastavNastrojZadani()
{
    *aktualniNastroj = QUESTFIELD;
}

void MainWindow::nastavNastrojSymbol()
{
     *aktualniNastroj = SYMBOLFIELD;
}

void MainWindow::nastavNastrojOznacovani()
{
     *aktualniNastroj = OZNACOVANI;
}

void MainWindow::smazWidget(int x, int y)
{
    ui->fields->removeWidget(ui->fields->itemAtPosition(y,x)->widget());
}

void MainWindow::otevriKrizovku()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("Otevři Křížovku"), "", "Soubory XML(*.xml)");
}

void MainWindow::ulozKrizovku()
{
    /*
    // skryju vytvareci listu kdyz je videt
    bool x = ui->widgetVytvareni->isVisible();
    ui->widgetVytvareni->setVisible(false);

    // skryjulustici listu kdyz je videt
    bool y = ui->widgetLusteni->isVisible();
    ui->widgetLusteni->setVisible(false);
    */

    QPixmap pix = QPixmap::grabWidget(centralWidget());

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Ulozit krizovku"), QApplication::applicationDirPath(), tr("Obrazky PNG (*.png)"));
    if (fileName=="") return;

    pix.save( fileName );

    /*
    ui->widgetVytvareni->setVisible(x);
    ui->widgetLusteni->setVisible(y);
    */
}

#define MAX(a,b) (((a)>(b))?(a):(b))

void MainWindow::novaKrizovka()
{
    // smazat co uz tam je
    for (int i = 0; i < krizovkaHeight; ++i) {
        for (int j = 0; j < krizovkaWidth; ++j) {
            delete policka->at(i)[j];
        }
    }

    krizovkaHeight = kVyska->text().toInt();
    krizovkaWidth = kSirka->text().toInt();

    // vytvoreni nove mrizky policek
    policka = new QVector< QVector<Field *> > ;
    for (int i = 0; i < krizovkaHeight; ++i)
    {
        QVector<Field *> *policka_buf = new QVector<Field *>;

        for (int j = 0; j < krizovkaWidth; ++j)
        {
            Field * policko;
            // po okraji jsou rovnou policka s
            if(i == 0 || j == 0 || i + 3 == j || 13- i == j) {
                if ((i == 0) && (j == 0))
                    policko = new SymbolField(j, i, policka);
                else
                    policko = new QuestField(j, i, policka);
                policko->mrizka = ui->fields;
                policko->aktualniNastroj = aktualniNastroj;
            } else {
                policko = new EditField(j, i, policka);
                policko->mrizka = ui->fields;
                policko->aktualniNastroj = aktualniNastroj;
            }
            policka_buf->append(policko);
            ui->fields->addWidget(policko,i,j,1,1);            
        }
        policka->append(*policka_buf);
    }

    // resize okna a nastaveni nejakych minimalnich rozmeru, funguje to blbe, ale aspon neco
    setMinimumSize(40 + 160 + MAX(krizovkaWidth,5) * 52, 150 + MAX(krizovkaHeight, 5) * 52);
    setMaximumSize(40 + 160 + MAX(krizovkaWidth,5) * 52, 150 + MAX(krizovkaHeight, 5) * 52);
}


void MainWindow::vyplnitNesmyslama()
{
    for (int i = 0; i < krizovkaHeight; ++i) {
        for (int j = 0; j < krizovkaWidth; ++j) {
            policka->at(i)[j]->setRandomText();
        }
    }
}
