#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    Player(int new_hp, float new_x, float new_y, float new_speed, float new_angle);

private:
    //Key CkeckPressKeyboard();
};

