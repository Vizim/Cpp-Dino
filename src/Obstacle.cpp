#include "Headers/Obstacle.hpp"

//each obstacle has similar behavior but differnt textures
//however, you can't set textures in the default with SFML causes it just draw a white rectangle
Obstacle::Obstacle()
{
}

Obstacle::~Obstacle() //deconstructor is auto generated
{
}

void Obstacle::renderObs(RenderWindow& window, bool gOver)
{
	if (!cactus.loadFromFile(CP) || !rocks.loadFromFile(RP))
	{
		printf(bRed "Error loading dino textures!\n" reset);
	}

	int randomTextureChoice = rand() % (10 - 1 + 1) + 1;

	if(!gOver)
	{
		if (randomTextureChoice >= 5)
		{
			obs.setTexture(cactus);
		}
		else
		{
			//change to barrels later
			obs.setTexture(rocks);
		}
	}


	window.draw(obs);
}