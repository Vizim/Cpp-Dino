#include "Headers\Dino.hpp"

Dino::Dino()
{
}

Dino::~Dino()
{
}

void Dino::renderDino(RenderWindow& window, bool gOver, bool onGround)
{
	//load dinosaur textures
	if (!dTexture.loadFromFile(WP) || !walk.loadFromFile(WP) || !L.loadFromFile(LP) || !R.loadFromFile(RP) || !S.loadFromFile(SP) || !D.loadFromFile(DP))
	{
		printf(bRed "Error loading dino textures!\n" reset);
	}

	if (onGround && !gOver)
	{
		dino.setTexture(R);
	}

	else if (gOver)
	{
		dino.setTexture(D);
	}
	else
	{
		dino.setTexture(S);
	}

	window.draw(dino);
}

/*
FloatRect Dino::dinoGlobalBounds()
{
	FloatRect bounds = dino.getGlobalBounds();

	return bounds;
}
*/