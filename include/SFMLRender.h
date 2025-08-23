#pragma once 
#include "IRender.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SFMLRender : public IRender {
private:
	sf::RenderWindow window;
public:
	SFMLRender();
	void drawRoofFloor();
	bool windowIsOpen() override;
	void processEvents() override;
	void clean() override;
	void render(const Map& map, std::vector<float> rays) override;
};