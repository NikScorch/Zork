
#include "include/enemy.h"

Enemy::Enemy() 
{
    // this->position = new Point(50, 50);
    this->position = new Point(250, 200);

    QImage image("res/dog.png");
    image = image.scaled(50, 50);
    QPixmap pixmapImage = QPixmap::fromImage(image);
    this->pixmap = new QGraphicsPixmapItem(pixmapImage);
    this->pixmap->setPos(this->position->getX(), this->position->getY());
}

void Enemy::tick()
{
    // bad roaming code
    switch (rand()%(4) + 1) {
        case 1:
            moveUp();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveDown();
            break;
        case 4:
            moveLeft();
            break;
    }
}
