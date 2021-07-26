#pragma once
#include "PCH.hpp"
#define reset "\033[0m"
#define bRed "\033[1m\033[31m" /* Bold Red */

using namespace sf;
using namespace std;

class Dino
{

public:
	//Sprite dinoAnimation[2];

	//define standing, left foot up, right foot up texture paths
	const string LP = "src/assets/dinoL.png";
	const string RP = "src/assets/dinoR.png";
	const string SP = "src/assets/start.png";
	const string DP = "src/assets/dead.png";
	const string WP = "src/assets/dTextMap.png";
	//dino texture declartion

	const int DINO_Y_BOTTOM = 190 - dino.getScale().y; //define the

	Dino();	 //default constructor
	~Dino(); //default deconstructor

	//Setters

	//draw dino
	void renderDino(RenderWindow& window, bool gOver, bool onGround);

	//set Position
	void dinoSetPosition(int x, int y)
	{
		dino.setPosition(x, y); //Change dino position

		//print where dino position was set optional but useful for debugging
		//printf("Current Dino Position:\n x-%d y-%d\n", x, y);
	}

	//getters

	FloatRect dinoGlobalBounds();

	int getDinoBottom()
	{
		return DINO_Y_BOTTOM;
	}

	const Sprite getDinoSprite()
	{

		return dino;
	}

	Sprite dino; //create dino sprite
	int dTw = 66;
	int dTh = 84;

	//IntRect dSrc(dTw, dTh);//texture rectangle to crop from our sprite map.

private:
	Texture dTexture, walk, R, L, S, D; //create textures used with dino sprite
	Clock spriteAniTime;
};
