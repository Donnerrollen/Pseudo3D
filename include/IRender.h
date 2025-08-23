#pragma once
#include <vector>

class Map;

class IRender {
public:
	virtual ~IRender() = default;
	virtual bool windowIsOpen() = 0;
	virtual void processEvents() = 0;
	virtual void clean() = 0;
	virtual void render(const Map& map, std::vector<float> rays) = 0;
};