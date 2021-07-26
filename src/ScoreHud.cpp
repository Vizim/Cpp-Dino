#include "Headers\ScoreHud.hpp"

Hud::Hud()
{
	if (!dFont.loadFromFile(fontPath))
	{
		printf("Error loading default font file.\n");
	}

	//set score properties
	scoreT.setFont(dFont);
	scoreT.setStyle(Text::Regular);
	scoreT.setString("Score");
	scoreT.setCharacterSize(60);
	scoreT.setFillColor(sf::Color::Black);

	gameOverSplash.setFont(dFont);
	gameOverSplash.setStyle(Text::Bold);
	gameOverSplash.setCharacterSize(100);
	gameOverSplash.setFillColor(sf::Color::Red);
	gameOverSplash.setString("Game Over!");



}

Hud::~Hud()
{
}


void Hud::updateHud()
{
	int cScore = (score.getElapsedTime().asMilliseconds())/300;
	scoreT.setString(to_string(cScore));
}


int Hud::getcScore()
{
	return cScore;
}

void Hud::renderHud(RenderWindow& window, bool gOver)
{
	if(gOver)
	{
		gameOverSplash.setOrigin(gameOverSplash.getGlobalBounds().width/2,(gameOverSplash.getGlobalBounds().height/2)+40);
		gameOverSplash.setPosition(window.getSize().x/2, window.getSize().y/2);
		window.draw(gameOverSplash);
		window.draw(scoreT);

	}
	else
	{
		//scoreT.setOrigin(window.getSize().x/2, scoreT.getGlobalBounds().width/2);
		scoreT.setPosition(window.getSize().x/2, 0);
		window.draw(scoreT);
	}

}