#pragma once

class Map;

class ICollision {
public:
	virtual ~ICollision() = default;
	virtual float DistToCollision(const Map& map, bool straight) const = 0;
	//virtual void FireCollision(const Map& map) = 0;
}; 