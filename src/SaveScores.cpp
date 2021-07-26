#include "Headers\SaveScores.hpp"

SaveScore::SaveScore()
{
}

SaveScore::~SaveScore()
{
}

void SaveScore::saveToFile(bool gOver)
{

	int saveScore = sHud->getcScore(); //get the current score from hud class;
	cout << saveScore << endl;

	if (gOver)
	{
		scoref.open("src/UserScores.txt", ios::app);								   //input out stream :: append data to file
		auto timestamp = chrono::system_clock::to_time_t(chrono::system_clock::now()); //get current system time

		scoref << "At time " << ctime(&timestamp) << " the score was " << saveScore << ".\n"; //

		scoref.close();
	}
}
