#ifndef ENTITY_H
#define ENTITY_H

#include "include/point.h"

#include <QObject>
#include <cstdint>
#include <qgraphicsitem.h>

struct Status {
    union {
        struct {
            uint8_t alive     :1;
            uint8_t canMove   :1;
        };
        uint8_t all;
    };
};

class Entity
{
public:
    Entity();
    Entity(const Entity& other);
    ~Entity();

    virtual void tick() = 0;

    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual Point *getPos();

    virtual void toggleMovement();

    virtual QGraphicsItem *getGraphicsItem();

private:

protected:
    Point *position;
    QGraphicsPixmapItem *pixmap;
    Status status;

    void updatePosition();

};

#endif // PLAYER_H 

