#ifndef PLAYER_H
#define PLAYER_H

#include "include/entity.h"
#include <QObject>
#include <qgraphicsitem.h>

class Player : public QObject, public Entity
{
    Q_OBJECT

public:
    Player();

    void tick() override;

    QGraphicsPixmapItem *getPixmap();

public slots:

private:

private slots:

};

#endif // PLAYER_H 

