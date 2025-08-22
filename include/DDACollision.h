#pragma once
#include "ICollision.h"

class DDACollision : public ICollision {
public:
	DDACollision() = default;
	float DistToCollision(const Map& map, bool straight) const override;
	//void FireCollision(const Map& map) override;
};