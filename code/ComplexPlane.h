#ifndef COMPLEXPLANE_H
#define COMPLEXPLANE_H

#include <SFML/Graphics.hpp>

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

class ComplexPlane : public sf::Drawable {
	public:
		ComplexPlane(int pixelWidth, int pixelHeight);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void zoomIn();
		void zoomOut();
		void setCenter(sf::Vector2i mousePixel);
		void setMouseLocation(sf::Vector2i mousePixel);
		void loadText(sf::Text& text);
		void updateRenderer();
	private:
		enum class State {CALCULATING, DISPLAYING};
		//functions
		size_t countIterations(sf::Vector2f coord);
		void iterationsToRGB(size_t count, uint8_t& r, uint8_t& g, uint8_t& b);
		sf::Vector2f mapPixelToCoords(sf::Vector2i mousePixel);
		//variables
		sf::VertexArray m_vArray;
		State m_state;
		sf::Vector2f m_mouseLocation;
		sf::Vector2i m_pixel_size;
		sf::Vector2f m_plane_center;
		sf::Vector2f m_plane_size;
		int m_zoomCount;
		float m_aspectRatio;;
};

#endif



