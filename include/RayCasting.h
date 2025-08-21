#include <vector>
#include "Map.h"

class RayCasting {
private: 
	float FieldOfView;
public:
	RayCasting();
	RayCasting(float field);
	std::vector<float> castsRays(const Map& map);
};