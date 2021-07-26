#include "PCH.hpp"		 //SFML
#include <bits/stdc++.h> //bunch of standard c++ librarys
#define reset "\033[0m"
#define bRed "\033[1m\033[31m" /* Bold Red */
#define green "\033[32m"	   /* Green */

using namespace sf;
using namespace std;

class Obstacle
{

public:
	Obstacle();	 //default constructor
	~Obstacle(); //default destructor

	string CP = "src/assets/cactusL.png"; //Cactus texture path
	string RP = "src/assets/rocks.png";

	void renderObs(RenderWindow& window, bool gOver); //draw obstacle to the window

	void obsSetPosition(int x, int y) //set object position
	{
		obs.setPosition(x, y);
		//printf(green "Obstacle Position:\n x-%d y-%d\n", x, y);
	}

	const Sprite getObsSprite()
	{
		return obs;
	}

private:
	Sprite obs; //default obs sprite
	Texture cactus;
	Texture rocks;
};