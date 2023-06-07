#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "map.h"

#include <QDialog>
#include <QTimer>
#include "qcustomplot.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

private slots:
    void on_startGameButton_clicked();
    void TimerSlot();

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void setGameMap(Map newGameMap);
    Map getGameMap();
    void paintMap();

private:
    Ui::GameWindow *ui;
    Map gameMap;
    QVector<double> x, tigersAmout, deersAmount;

    QTimer *timer;
    int time;

};

#endif // GAMEWINDOW_H
