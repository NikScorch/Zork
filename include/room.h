#ifndef ROOM_H
#define ROOM_H

#include "include/entity.h"
#include <string>
#include <vector>

class Room 
{
public:
    Room();
    ~Room();

    void setName(std::string &name);
    std::string getName();

    std::vector<Entity*> *getEntities();

private:
    std::string name;
    std::vector<Entity*> entities;
    
};

#endif  // room_h
