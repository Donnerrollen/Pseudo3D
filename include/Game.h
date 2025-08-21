#include <Map.h>
#include <RayCasting.h>

class Game {
public: 
	Game();
	Game(int w, int h);
	Game(int w, int h, float field);
	Map map;
	RayCasting raycaster;
};