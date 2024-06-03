
#include "include/settings.h"
#include "include/entity.h"
#include "include/point.h"

Entity::Entity() 
{
    this->position = new Point();
    this->pixmap = new QGraphicsPixmapItem();
    this->pixmap->setPos(this->position->getX(), this->position->getY());

    this->status.all = 0b11111111;
}

Entity::Entity(const Entity& other)
{
    this->position = new Point(*other.position);
    this->pixmap = new QGraphicsPixmapItem(other.pixmap);
}

Entity::~Entity()
{
    delete position;
    delete pixmap;
}

void Entity::moveUp() 
{
    if (this->status.canMove) {
        // position->setY(position->getY() - 10);
        position->y -= settings::ENTITY_MOVEMENT_STEP;      // direct access with friendship
        updatePosition();
    }
}

void Entity::moveDown() 
{
    if (this->status.canMove) {
        // position->setY(position->getY() + 10);
        position->y += settings::ENTITY_MOVEMENT_STEP;      // direct access with friendship
        updatePosition();
    }
}

void Entity::moveLeft() 
{
    if (this->status.canMove) {
        // position->setX(position->getX() - 10);
        position->x -= settings::ENTITY_MOVEMENT_STEP;      // direct access with friendship
        updatePosition();
    }
}

void Entity::moveRight() 
{
    if (this->status.canMove) {
        // position->setX(position->getX() + 10);
        position->x += settings::ENTITY_MOVEMENT_STEP;      // direct access with friendship
        updatePosition();
    }
}

void Entity::updatePosition() 
{
    // pixmap->setPos(position->getX(), position->getY());
    pixmap->setPos(position->x, position->y);       // direct access with friendship
}

void Entity::toggleMovement()
{
    this->status.canMove = ! this->status.canMove;
}

Point *Entity::getPos() 
{ 
    return position; 
}

QGraphicsItem *Entity::getGraphicsItem() 
{
    return pixmap;
}

