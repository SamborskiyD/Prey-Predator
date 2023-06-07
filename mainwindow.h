#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <QRegExpValidator>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inputCheck(QLineEdit& input);


private slots:
    void on_startButton_clicked();

    void on_inputWidth_editingFinished();

    void on_inputHeight_editingFinished();

    void on_inputDeersAmount_editingFinished();

    void on_inputTigersAmount_editingFinished();

    void on_inputDeerDieAge_editingFinished();

    void on_inputTigerDieAge_editingFinished();

    void on_inputDeerBirthAge_editingFinished();

    void on_inputTigerBirthAge_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
