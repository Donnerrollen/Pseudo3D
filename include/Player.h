#pragma once
#include "Entity.h"
#include <ICollision.h>
#include <memory>
#include "IInputHandler.h"

class Map;

class Player :
    public Entity
{
public:
    Player(int new_hp, float new_x, float new_y, float new_speed, float new_angle);
    void Update(const ICollision& collisionsystem, const Map& map);

private:
    std::unique_ptr<IInputHandler> inputHandler;
};

