#include "ComplexPlane.h"
#include <complex>
#include <sstream>

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
	m_pixel_size = { pixelWidth, pixelHeight };
	m_aspectRatio = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth);
	m_plane_center = { 0.0f, 0.0f };
	m_plane_size.x = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = sf::State::CALCULATING; //
	m_vArray.setPrimitiveType(sf::Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}

void draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_vArray);
}

void complexPlane::updateRenderer() {

	if (m_State == sf::State::CALCULATING) {
		for (int i {0}; i < m_pixel_size.y; i++) {
			for (int j {0}; j < m_pixel_size.x; j++) {

				sf::Uint8 r, g, b;
				size_t iters {0};

				m_vArray[ j + i * pixelWidth].position = { (float)j, (float)i };

				iters = countIterations(mapPixelToCoords(sf::Vector2i(j, i));//check
				iterationsToRGB(iters, r, g, b);

				vArray[j + i * pixelWidth].color = { r, g, b };
			}
		}
		m_State = sf::State::DISPLAYING;
	}

}

void ComplexPlane::zoomIn() {
	m_zoomCount++;
	sf::Vector2f temp;
	float scale = pow(BASE_ZOOM, m_zoomCount);

	temp.x = BASE_WIDTH * scale;
	temp.y = BASE_HEIGHT * m_aspectRatio * scale;

	m_plane_size = temp;
	m_State = sf::State::CALCULATING; //
}

void ComplexPlane::zoomOut() {
	m_zoomCount--;

	sf::Vector2f temp;
	float scale = pow(BASE_ZOOM, m_zoomCount);

	temp.x = BASE_WIDTH * scale;
	temp.y = BASE_HEIGHT * m_aspectRatio * scale;

	m_plane_size = temp;
	m_State = sf::State::CALCULATING; //
}

void ComplexPlane::setCenter(sf::Vector2i mousePixel) {
	m_plane_center = mapPixelToCoords(mousePixel);
	m_State = sf::State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel) {
	m_mouseLocation = mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(Text& text) {

	ostringstream txt;

	txt << "Mandelbrot Set\n";
	txt << "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")\n";
	txt << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n";
	txt << "Left Click to Zoom in\n" << "Right-click to Zoom out";

	text.setString(txt.str());

}

//private member functions

size_t ComplexPlane::countIterations(Vector2f coord) {
	complex<double> z(coord.x, coord.y);
	size_t i {0};
	while((z.real() * z.real() + z.imag() + z.imag()) < 4.0 && i < MAX_ITER) {
        z = z*z + c;
        i++;
    }
	return i;
}
	
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {
	if (count >= MAX_ITER) {
		r = 0; 
		g = 0;
		b = 0;
	}
	else {
		if (count > 0 && count <= 5) { r = 255 - count * 51; g = 0; b = 255; }
		else if ( count > 5 && count <= 15 ) { r = 0; g = 0 + count * 25; b = 255; }
		else if ( count > 15 && count <= 35) { r = 0; g = 255; b = 255 - count * 12; }
		else if ( count > 35 && count <= 51) { r = 0 + count * 15; g = 255; b = 0; }
		else if ( count > 51 && count <= 63) { r = 255; g = 255 - count * 21; b = 0; }
	}
}

sf::Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
		
	   sf::Vector2f planeCoord;
	   planeCoord.x = ((mousePixel.x - 
		//:UNFINISHED
}





