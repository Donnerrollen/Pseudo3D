#include "SFMLRender.h"
#include "Map.h"
#include "config.h"
#include "SFML/Graphics.hpp"

SFMLRender::SFMLRender() {
	window.create(sf::VideoMode({ screenWidth, screenHeight }), "Pseudo3D");
}

bool SFMLRender::windowIsOpen() {
	return window.isOpen();
}

void SFMLRender::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
                return;
            }
        }
    }
}

//Ќадо отдельно рисовать небо с землей, потом можно добавить анимацию
void SFMLRender::clean() {
	window.clear();
}

void SFMLRender::drawRoofFloor() {
	//пол (37, 50, 30)

	sf::RectangleShape rectangle(sf::Vector2f(screenWidth, screenHeight / 2));
	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color(37, 47, 64));
	window.draw(rectangle);
	
	rectangle.setPosition(0, screenHeight / 2);
	rectangle.setFillColor(sf::Color(37, 50, 30));
	window.draw(rectangle);

}

void SFMLRender::render(const Map& map, std::vector<float> rays) {
	float unitWidthWall;
	float oneStepToWallHeight;
	float heightWallRay;

	sf::RectangleShape wallRectangle;

	drawRoofFloor();

	unitWidthWall = float(screenWidth / rayCount);

	oneStepToWallHeight = screenHeight / 2;	

	for (int i = 0; i < rayCount; i += 1) {
		heightWallRay = oneStepToWallHeight / rays[i];



		wallRectangle.setSize(sf::Vector2f(unitWidthWall, heightWallRay));
		wallRectangle.setPosition(unitWidthWall * i, screenHeight / 2 - heightWallRay / 2);
		wallRectangle.setFillColor(sf::Color(std::min(68 * 1.2f / rays[i], 116.0f), std::min(51 * 1.2f / rays[i], 102.0f), std::min(39 * 1.2f / rays[i], 78.0f)));
		window.draw(wallRectangle);
	}
	window.display();
}