
#include "include/settings.h"
#include "include/gamestate.h"
#include "include/player.h"
#include "include/point.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>
#include <QImage>
#include <qnamespace.h>
#include <qpixmap.h>

#include <algorithm>

QString TITLE("Zork Game");

GameState::GameState()
{
    setWindowTitle(TITLE);

    this->scene = new QGraphicsScene();
    this->view = new QGraphicsView(scene);
    setCentralWidget(view);

    scene->setBackgroundBrush(Qt::white);
    scene->setSceneRect(0, 0, 800, 600);

    // Add entities to the world
    this->player = new Player();
    scene->addItem(this->player->getGraphicsItem());

    // load starting room
    currentRoomPos = new Point(settings::MAP_STARTING_ROOM_X, settings::MAP_STARTING_ROOM_Y);
    loadRoom(currentRoomPos);

    // Set game tickrate    -- Run 20 times a second
    tickTimer = new QTimer(this);
    connect(tickTimer, SIGNAL(timeout()), this, SLOT(tick()));
    tickTimer->start(50);       // 20tps

    frameTimer = new QTimer(this);
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(render()));
    frameTimer->start(16);      // 60fps
}

void GameState::tick() 
{
    // room change
    /*
     * First, check to see if the player is trying to change roomPos
     * find the direction of the new room
     * find the roomPos of the new room
     * check if new roomPos is valid
     */
    // TODO: player should hit the edge rather than bouncing to the
    //       opposite side of the room when unable to move to next room
    int x = player->getPos()->getX();
    int y = player->getPos()->getY();
    if (x < 0 || x > width() || y < 0 || y > height()) 
    {
        if (x < 0) 
        {
            currentRoomPos->setX(std::max(currentRoomPos->getX() - 1, 0));
            player->getPos()->setX(width()-50);

        }
        if (x > width())
        {
            currentRoomPos->setX(std::min(currentRoomPos->getX() + 1, settings::MAP_WIDTH - 1));
            player->getPos()->setX(50);
        }
        if (y < 0)
        {
            currentRoomPos->setY(std::max(currentRoomPos->getY() - 1, 0));
            player->getPos()->setY(height()-50);
        }
        if (y > height())
        {
            currentRoomPos->setY(std::min(currentRoomPos->getY() + 1, settings::MAP_HEIGHT - 1));
            player->getPos()->setY(50);
        }
        unloadRoom();
        loadRoom(currentRoomPos);
   }

    // update all entities
    for (int i = 0; i < currentRoom->getEntities()->size(); i++) {
        currentRoom->getEntities()->at(i)->tick();
    }
}

void GameState::render()
{
    // im not sure i need a separate renderer?
    // Qt handles updating the screen when properties are changed
}

void GameState::unloadRoom()
{
    for (Entity *entity: *currentRoom->getEntities()) 
    {
        scene->removeItem(entity->getGraphicsItem());
    }
}

void GameState::loadRoom(Point *roomPos)
{
    currentRoom = &map[roomPos->getX()][roomPos->getY()];
    for (Entity *entity: *currentRoom->getEntities()) 
    {
        scene->addItem(entity->getGraphicsItem());
    }
}

void GameState::keyPressEvent(QKeyEvent *event) {
    switch (event->key())
            {
                case Qt::Key_Escape:
                    QApplication::quit();
                    break;

                case Qt::Key_W:
                    player->moveUp();
                    break;
                case Qt::Key_A:
                    player->moveLeft();
                    break;
                case Qt::Key_S:
                    player->moveDown();
                    break;
                case Qt::Key_D:
                    player->moveRight();
                    break;
                default:
                    // Handle other keys if needed
                    QWidget::keyPressEvent(event); // Call base class implementation for unhandled keys
            }
}
