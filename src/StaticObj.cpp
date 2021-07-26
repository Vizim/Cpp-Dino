#include "Headers\StaticObj.hpp"




Objects::Objects()
{

	groundL.setPosition(0, 260);
	groundL.setFillColor(Color::Black);

}

Objects::~Objects()
{

}



void Objects::drawGround(RenderWindow& window)
{

	groundL.setSize(Vector2f(window.getSize().x, 3));
	window.draw(groundL);
}