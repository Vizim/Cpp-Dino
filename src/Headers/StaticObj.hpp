#include "PCH.hpp"		 //SFML cross platform support
#include <bits/stdc++.h> //bunch of standard c++ librarys




using namespace sf;

//this class is essentially the prototype for all of the static enviroment objects in the game.
//Horizon line, clouds etc

class Objects
{

public:

	Objects();//defualt constuctor
	~Objects();//defualt destructor

	void drawGround(RenderWindow& window); //draw ground object to window and create it
	void drawClouds(RenderWindow& window); //draw cloud objects to sky and create them


private:
	RectangleShape groundL;


};