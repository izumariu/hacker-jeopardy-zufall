#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int name_prev = 0;
int n_s_a_prev= 0;
bool first_gen = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generate_clicked()
{
    if (ui->checkBox->checkState()) {
    QMessageBox msgBox;
    int n_s_a_c;
    n_s_a_prev == 4 ? n_s_a_c = 1 : n_s_a_c = n_s_a_prev+1;
    switch(n_s_a_c) {
        case 1:
            msgBox.setText("Der Zufall waehlt:");
            ui->lineEdit_1->text()!="" ? msgBox.setInformativeText(ui->lineEdit_1->text()) : msgBox.setInformativeText("Spieler 1");
            break;
        case 2:
            msgBox.setText("Der Zufall waehlt:");
            ui->lineEdit_2->text()!="" ? msgBox.setInformativeText(ui->lineEdit_2->text()) : msgBox.setInformativeText("Spieler 2");
            break;
        case 3:
            msgBox.setText("Der Zufall waehlt:");
            ui->lineEdit_3->text()!="" ? msgBox.setInformativeText(ui->lineEdit_3->text()) : msgBox.setInformativeText("Spieler 3");
            break;
        case 4:
            msgBox.setText("Der Zufall waehlt:");
            ui->lineEdit_4->text()!="" ? msgBox.setInformativeText(ui->lineEdit_4->text()) : msgBox.setInformativeText("Spieler 4");
            break;
    }
    msgBox.exec();
    n_s_a_prev = n_s_a_c;
    } else {
        QMessageBox msgBox;
        srand(time(0));
        int name_c = (rand()%4)+1;
        while (name_c == name_prev) {
            name_c = (rand()%4)+1;
        }
        switch(name_c) {
            case 1:
                msgBox.setText("Der Zufall waehlt:");
                ui->lineEdit_1->text()!="" ? msgBox.setInformativeText(ui->lineEdit_1->text()) : msgBox.setInformativeText("Spieler 1");
                break;
            case 2:
                msgBox.setText("Der Zufall waehlt:");
                ui->lineEdit_2->text()!="" ? msgBox.setInformativeText(ui->lineEdit_2->text()) : msgBox.setInformativeText("Spieler 2");
                break;
            case 3:
                msgBox.setText("Der Zufall waehlt:");
                ui->lineEdit_3->text()!="" ? msgBox.setInformativeText(ui->lineEdit_3->text()) : msgBox.setInformativeText("Spieler 3");
                break;
            case 4:
                msgBox.setText("Der Zufall waehlt:");
                ui->lineEdit_4->text()!="" ? msgBox.setInformativeText(ui->lineEdit_4->text()) : msgBox.setInformativeText("Spieler 4");
                break;
        }
        msgBox.exec();
        name_prev = name_c;
    }
}

void MainWindow::on_newRound_clicked()
{
    QMessageBox sureConfirm;
    sureConfirm.setText("Sicher?");
    sureConfirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    sureConfirm.setDefaultButton(QMessageBox::No);
    int ret = sureConfirm.exec();
    switch(ret) {
        case QMessageBox::Yes:
            ui->lineEdit_1->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            break;
        case QMessageBox::No:
            break;
        case QMessageBox::Cancel:
            break;
    }
}
