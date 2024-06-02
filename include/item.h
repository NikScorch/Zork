#ifndef ITEM_H
#define ITEM_H

#include "include/entity.h"

class Item: public Entity
{
public:
    Item();

    void tick() override;

};

#endif  
