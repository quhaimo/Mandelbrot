#include "ComplexPlane.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
	
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);
	RenderWindow window(vm, "Mandelbrot Set", Style::Default);
	
	Font font("AdwaitaSans-Regular.ttf");
	Text text(font);
	
	while (window.isOpen()) {
		///Input
		while (const optional event = window.pollEvent()) {
			
			if (event->is<Event::Closed>()) {
				window.close();
			}
			
			if (const auto* mb = event->getIf<Event::MouseButtonPressed>()) {
				if (mb->button == Mouse::Button::Left) {
					//TODO
				}
				else if (mb->button == Mouse::Button::Right) {
					//TODO
				}
			}

			if (const auto* mouseMoved = event->getIf<Event::MouseButtonPressed>() {
				//TODO
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Scan::Escape)) {
			window.close();
		}
		
		///Update

		
		///Draw
		window.clear();
		//window.draw(...);
		window.display();
	}
}
