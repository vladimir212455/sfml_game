#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;
void getplayercoordinateforview(float x, float y) { 
	float tempX = x; float tempY = y;
	if (x < 320) tempX = 320;
	if (y < 240) tempY = 240;
	if (y > 554) tempY = 554;
	view.setCenter(tempX, tempY);
}
void changeview() {
	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f);
	}
	if (Keyboard::isKeyPressed(Keyboard::R)) {
		view.rotate(1);
	}
	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);
	}
	if (Keyboard::isKeyPressed(Keyboard::P)) {
		view.setSize(540, 380);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
	}
}