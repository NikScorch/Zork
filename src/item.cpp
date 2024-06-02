
#include "include/item.h"

Item::Item()
{
    // this->position = new Point(50, 50);
    this->position = new Point(rand()%800, rand()%600);

    QImage image("res/coin.png");
    image = image.scaled(50, 50);
    QPixmap pixmapImage = QPixmap::fromImage(image);
    this->pixmap = new QGraphicsPixmapItem(pixmapImage);
    this->pixmap->setPos(this->position->getX(), this->position->getY());

}

void Item::tick()
{

}
