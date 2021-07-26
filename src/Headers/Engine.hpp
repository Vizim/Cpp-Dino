#pragma once

#include "PCH.hpp"		 //SFML cross platform support
#include <bits/stdc++.h> //bunch of standard c++ librarys

//These are pretty self explanatory
#include "Headers\Dino.hpp"
#include "Headers\Obstacle.hpp"
#include "Headers\SaveScores.hpp"
#include "Headers\ScoreHud.hpp"
#include "Headers\StaticObj.hpp"


using namespace sf;
using namespace std;

class Engine
{
public:
	//Default Engine constructor
	Engine();
	//Destructor
	~Engine();
	//Main game loop
	void gameLoop();
	RenderWindow* window;

	int randomObsDist;

	//gravity value to decreae jump speed
	const int grav = 4; //4
	const int jumpVelocity = 2; //8

	//set the speed the obstacles come at the player
	int obsVelocity = 6;

	bool jumping = false;
	bool onGround = true;

	//dino x and y position integers
	int x = 0;
	int y = 0;

	//Obstacle x and y position integers
	int obstacleX = 0;
	int obstacleY = 0;

private:
	//Window pointer, video declartion, input event declaration
	SoundBuffer jSoundBuff;
	Sound jSound;
	Event in;
	Objects* obj;
	Dino* dino;
	Obstacle* obs;
	Hud* hud;
	SaveScore* save;

	bool gOver;
};