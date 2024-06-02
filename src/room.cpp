
#include "include/settings.h"
#include "include/room.h"
#include "include/enemy.h"
#include "include/entity.h"
#include "include/item.h"
#include <string>
#include <vector>

Room::Room() {
    for (int i = 0; i < rand()%(settings::ROOM_MAX_ENEMIES) + 1; i++) 
    {
        Enemy *newEnemy = new Enemy();
        if (rand()%5==0)
            newEnemy->toggleMovement();
        entities.push_back(newEnemy);
    }

    for (int i = 0; i < 10; i++)
    {
        entities.push_back(new Item());
    }
}

Room::~Room() {
    // the following code causes a seg fault, i do not know why
    // you would think clean up would be easy but apparently not
    for (Entity* entity: entities) 
    {
        delete entity;
    }
    entities.clear();
    // for (int i = 0; i < entities.size(); i++) {
    //     delete entities[i];
    // }
}

void Room::setName(std::string &name)
{
    this->name = name;
}

std::string Room::getName()
{
    return this->name;
}

std::vector<Entity*> *Room::getEntities()
{
    return &entities;
}

