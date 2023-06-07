#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "map.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputCheck(QLineEdit& input){

    QRegExpValidator validator(QRegExp("^-?\\d+$"));

    QString text = input.text();
    int pos = 0;

    if (validator.validate(text, pos) != QValidator::Acceptable) {
        QMessageBox::warning(nullptr, "Error", "Not a number has been entered. Please enter a number");
        input.clear();
    }
}

void MainWindow::on_startButton_clicked()
{
    bool allFieldsNotEmpty = true;
    allFieldsNotEmpty = !ui->inputWidth->text().isEmpty();
    allFieldsNotEmpty = !ui->inputHeight->text().isEmpty();
    allFieldsNotEmpty = !ui->inputDeerDieAge->text().isEmpty();
    allFieldsNotEmpty = !ui->inputDeerBirthAge->text().isEmpty();
    allFieldsNotEmpty = !ui->inputDeersAmount->text().isEmpty();
    allFieldsNotEmpty = !ui->inputTigerBirthAge->text().isEmpty();
    allFieldsNotEmpty = !ui->inputTigersAmount->text().isEmpty();
    allFieldsNotEmpty = !ui->inputTigerDieAge->text().isEmpty();
    if(!allFieldsNotEmpty){
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }
    else {
        GameWindow newWindow;
        Map newGameMap(ui->inputWidth->text().toInt(),
                       ui->inputHeight->text().toInt(),
                       ui->inputDeerDieAge->text().toInt(),
                       ui->inputTigerDieAge->text().toInt(),
                       ui->inputDeerBirthAge->text().toInt(),
                       ui->inputTigerBirthAge->text().toInt());
        newGameMap.start(ui->inputDeersAmount->text().toInt(), ui->inputTigersAmount->text().toInt());

        newWindow.setGameMap(newGameMap);


        newWindow.setModal(true);
        newWindow.exec();
    }

}


void MainWindow::on_inputWidth_editingFinished()
{
    inputCheck(*ui->inputWidth);
    if (ui->inputWidth->text().toInt() < 10){
        QMessageBox::warning(nullptr, "Error", "Width can't be less then 10");
        ui->inputWidth->clear();
    }
}


void MainWindow::on_inputHeight_editingFinished()
{
    inputCheck(*ui->inputHeight);
    if (ui->inputHeight->text().toInt() < 10){
        QMessageBox::warning(nullptr, "Error", "Height can't be less then 10");
        ui->inputHeight->clear();
    }
}


void MainWindow::on_inputDeersAmount_editingFinished()
{
    inputCheck(*ui->inputDeersAmount);
}


void MainWindow::on_inputTigersAmount_editingFinished()
{
    inputCheck(*ui->inputTigersAmount);
}


void MainWindow::on_inputDeerDieAge_editingFinished()
{
    inputCheck(*ui->inputDeerDieAge);
}


void MainWindow::on_inputTigerDieAge_editingFinished()
{
    inputCheck(*ui->inputTigerDieAge);
}


void MainWindow::on_inputDeerBirthAge_editingFinished()
{
    inputCheck(*ui->inputDeerBirthAge);
}


void MainWindow::on_inputTigerBirthAge_editingFinished()
{
    inputCheck(*ui->inputTigerBirthAge);
}

