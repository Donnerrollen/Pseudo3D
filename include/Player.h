#pragma once
#include <memory>
#include <chrono>

#include "Entity.h"
#include "ICollision.h"
#include "IInputHandler.h"



class Map;

class Player :
    public Entity
{
public:
    Player(int new_hp, float new_x, float new_y, float new_speed, float new_angle);
    void update(const ICollision& collisionsystem, const Map& map, float dir_time);
    void setInputHandler(std::unique_ptr<IInputHandler> new_inputHandler) const;

private:
    mutable std::unique_ptr<IInputHandler> inputHandler;
};

