#include "ComplexPlane.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
	
	sf::VideoMode vm = sf::VideoMode::getDesktopMode();
	sf::Vector2u screen = sf::VideoMode::getDesktopMode().size;
	RenderWindow window(vm, "Mandelbrot Set", Style::Default);
	Font font("AdwaitaSans-Regular.ttf");
	Text text(font);
	text.setCharacterSize(24);
	
	ComplexPlane mandel(screen.x, screen.y);
	while (window.isOpen()) {
		///Input
		while (const optional event = window.pollEvent()) {
			
			if (event->is<Event::Closed>()) {
				window.close();
			}
			
			if (const auto* mb = event->getIf<Event::MouseButtonPressed>()) {
				if (mb->button == Mouse::Button::Left) {
					mandel.zoomIn();
					mandel.setCenter(sf::Mouse::getPosition(window));
				}
				else if (mb->button == Mouse::Button::Right) {
					mandel.zoomOut();
					mandel.setCenter(sf::Mouse::getPosition(window));
				}
			}

			if (const auto* mouseMoved = event->getIf<Event::MouseMoved>()) {
				mandel.setMouseLocation(sf::Mouse::getPosition(window));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Scan::Escape)) {
			window.close();
		}
		
		///Update

		
		///Draw
		//window.draw(...);

		mandel.updateRenderer();
		mandel.loadText(text);

		window.clear();

		mandel.draw(window, sf::RenderStates::Default);
		window.draw(text);
		
		
		window.display();
	}
}
