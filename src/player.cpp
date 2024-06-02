
#include "include/player.h"
#include "include/point.h"

Player::Player() 
{
    // this->position = new Point(50, 50);
    this->position = new Point(50, 50);

    QImage catImage("res/cat.png");
    catImage = catImage.scaled(50, 50);
    QPixmap catPixmap = QPixmap::fromImage(catImage);
    this->pixmap = new QGraphicsPixmapItem(catPixmap);
    this->pixmap->setPos(this->position->getX(), this->position->getY());
}

void Player::tick()
{

}

QGraphicsPixmapItem *Player::getPixmap() 
{
    return pixmap;
}

