#pragma once

#include "PCH.hpp"		 //SFML cross platform support
#include <bits/stdc++.h> //bunch of standard c++ librarys

using namespace sf;
using namespace std;

class Hud
{
public:
	Hud();
	~Hud();
	void updateHud();								  //calculate the hude elements and  update them.
	void renderHud(RenderWindow& window, bool gOver); //Set the score element attributes and draw them to the screen
	void resetScoreClock();

	//get the current user score and highscore as a string

	int getcScore();
	int gethScore();

	string fontPath = "src/assets/ARCADE.ttf";

private:
	int cScore, hScore; //current score & highscore
	Clock score;
	Font dFont; // Defualt hud font
	Text scoreT, hScoreLabel, gameOverSplash;
};