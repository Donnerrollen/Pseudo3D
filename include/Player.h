#pragma once
#include "Entity.h"
#include "ICollision.h"
#include "IInputHandler.h"
#include <memory>


class Map;

class Player :
    public Entity
{
public:
    Player(int new_hp, float new_x, float new_y, float new_speed, float new_angle);
    void update(const ICollision& collisionsystem, const Map& map);
    void setInputHandler(std::unique_ptr<IInputHandler> new_inputHandler) const;

private:
    mutable std::unique_ptr<IInputHandler> inputHandler;
};

