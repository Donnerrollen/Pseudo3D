#pragma once

class Map;

class ICollision {
public:
	virtual ~ICollision();
	virtual float DistToCollision(const Map& map) = 0;
	//virtual void FireCollision(const Map& map) = 0;
}; 