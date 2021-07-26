#pragma once
#include "Headers/ScoreHud.hpp"
#include <bits/stdc++.h>


using namespace std;


class SaveScore{

public:
	SaveScore();
	~SaveScore();

	void saveToFile(bool gOver);


private:
	int savedScore;
	fstream scoref; //score file
	Hud* sHud;



};