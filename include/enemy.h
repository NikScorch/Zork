#ifndef ENEMY_H
#define ENEMY_H

#include "include/entity.h"
#include <qgraphicsitem.h>

class Enemy: public Entity
{
public:
    Enemy();

    void tick() override;

};

#endif // ENEMY_H
