#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "include/settings.h"
#include "include/player.h"
#include "include/room.h"

#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qgraphicsitem.h>
#include <qmainwindow.h>

// class GameState : public QWidget 
class GameState : public QMainWindow
{
    Q_OBJECT

public:
    GameState();
    // GameState(QMainWindow);

public slots:
    void render();
    void tick();

private:
    QTimer *tickTimer;
    QTimer *frameTimer;

    QMainWindow *parent;
    QGraphicsScene *scene;
    QGraphicsView *view;

    Player *player;
    
    Room map[settings::MAP_WIDTH][settings::MAP_HEIGHT];
    Room *currentRoom;
    Point *currentRoomPos;

    void unloadRoom();
    void loadRoom(Point *roomPos);

private slots:

protected:
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // GAMESTATE_H 

