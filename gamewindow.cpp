#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    ui->graphWidget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->graphWidget->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->graphWidget->setInteraction(QCP::iRangeZoom, true);
    ui->graphWidget->setInteraction(QCP::iRangeDrag, true);
    ui->graphWidget->legend->setVisible(true);
    ui->graphWidget->legend->setFont(QFont("Helvetica",9));
    ui->graphWidget->yAxis->setRange(0, 100);
    ui->graphWidget->xAxis->setRange(-50, 50);

    ui->mapLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setGameMap(Map newGameMap){
    gameMap = newGameMap;
}

Map GameWindow::getGameMap(){
    return gameMap;
}

void GameWindow::paintMap()
{
    Coordinates tempCoord;
    QImage image(ui->mapLabel->width(), ui->mapLabel->height(), QImage::Format_RGB32);
    image.fill(QColor::fromRgb(	255, 229, 180));

    QPainter painter(&image);

    double pixelWidth = ui->mapLabel->width()/gameMap.getMapWidth();
    double pixelHeight = ui->mapLabel->height()/gameMap.getMapHeight();

    painter.setPen(QColor::fromRgb(220,220,220));

    double cellWidth = 0;
    double cellHeight = 0;
    for (int i = 0; i < ui->mapLabel->width()/pixelWidth; i++){

        painter.drawLine(cellWidth, 0, cellWidth, ui->mapLabel->height());
        cellWidth += pixelWidth;
    }

    for (int i = 0; i < ui->mapLabel->height()/pixelHeight; i++){

        painter.drawLine(0, cellHeight, ui->mapLabel->width(), cellHeight);
        cellHeight += pixelHeight;
    }

    painter.setRenderHint(
        QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    painter.setBrush(Qt::darkGreen);


    for (int i = 0; i < gameMap.getGrassArray().size(); i++){
        tempCoord = gameMap.getGrassArray()[i].getPosition();
        painter.drawRect(tempCoord.getX()*pixelWidth, tempCoord.getY()*pixelHeight, pixelWidth, pixelHeight);
    }

    painter.setRenderHint(
        QPainter::Antialiasing);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);

    for (int i = 0; i < gameMap.getDeersPopulation().size(); i++){
        tempCoord = gameMap.getDeersPopulation()[i].getPosition();
        painter.drawRect(tempCoord.getX()*pixelWidth, tempCoord.getY()*pixelHeight, pixelWidth, pixelHeight);
    }

    painter.setRenderHint(
        QPainter::Antialiasing);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);

    for (int i = 0; i < gameMap.getTigersPopulation().size(); i++){
        tempCoord = gameMap.getTigersPopulation()[i].getPosition();
        painter.drawRect(tempCoord.getX()*pixelWidth, tempCoord.getY()*pixelHeight, pixelWidth, pixelHeight);
    }

    QLabel label;
    ui->mapLabel->setPixmap(QPixmap::fromImage(image));
}


void GameWindow::on_startGameButton_clicked()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    ui->graphWidget->clearGraphs();

    time = 0;
    ui->graphWidget->addGraph();
    ui->graphWidget->addGraph();
    timer->start(2000);
    x.clear();
    deersAmount.clear();
    tigersAmout.clear();
    gameMap.getDeersPopulation().clear();
    gameMap.getTigersPopulation().clear();
    gameMap.getGrassArray().clear();
}

void GameWindow::TimerSlot()
{
    gameMap.refresh();
    x.push_back(time/100);
    deersAmount.push_back(gameMap.getDeersPopulation().size());
    tigersAmout.push_back(gameMap.getTigersPopulation().size());

    ui->graphWidget->xAxis->setRange(time/100 - 50, time/100 + 50);

    time += 2000;

    QPen pen1;
    pen1.setWidth(2);
    pen1.setColor(QColor(0, 0,255));
    ui->graphWidget->graph(0)->setPen(pen1);
    ui->graphWidget->graph(0)->setName("Deers");
    ui->graphWidget->graph(0)->addData(x, deersAmount);

    QPen pen2;
    pen2.setWidth(2);
    pen2.setColor(QColor(255,0,0));
    ui->graphWidget->graph(1)->setPen(pen2);
    ui->graphWidget->graph(1)->setName("Tigers");
    ui->graphWidget->graph(1)->addData(x, tigersAmout);

    ui->graphWidget->replot();

    paintMap();
}

