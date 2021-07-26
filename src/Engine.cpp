#include "Headers/Engine.hpp"
#define width 600
#define height 300
#define MaxFPS 60
#define fontPath "assets/Font"

Engine::Engine()
{
	window = new RenderWindow(VideoMode(width, height), "ZE Dino Run"); //intialize window
	window->setFramerateLimit(MaxFPS);									//sets the max frame limit of the window
	dino = new Dino();													//dino class refrence
	hud = new Hud();													//hud class refrence
	obs = new Obstacle();												//Obstacle class refrence
	obj = new Objects();												//static objects class refrence
	save = new SaveScore();												//Save score class refrence

	y = dino->getDinoBottom(); //call this function from the dino class to get the bottom point of the dinosaur
	x = 60;					   //set dinosaur defualt x position

	//this is the level the dinosaur sits at by default so setting the obstacles to this height lines everything up with the player
	obstacleY = 225;
	gOver = false;

	if (!jSoundBuff.loadFromFile("src/assets/jumpS.wav"))
	{
		printf("Sounds not loaded \n");
	}

	jSound.setBuffer(jSoundBuff);
}

//deconstructor auto generates
Engine::~Engine()
{
}

//This is the main game loop all of the logic of the game can be found here.

void Engine::gameLoop()
{
	while (window->isOpen()) //while the window is open
	{
		srand(time(0)); //generate a new seed every game tick

		Event input; //create an event called input

		while (window->pollEvent(input))
		{
			if (input.type == Event::Closed) //if you press the X
			{
				window->close(); //close the window
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //if you press the escape key at any point
		{
			window->close(); //close the window / terminate the game
		}

		//if the space or up key is pressed
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Up))
		{
			//and the dino is on the ground and jumping
			if (onGround && !jumping)
			{
				//set currently jumping = true;
				jSound.play();
				jumping = true;
				onGround = false;
			}
		}

		if (jumping) //if currently jumping
		{
			y -= grav; //subtract the value of gravity which is 5
					   //from the total intial value which is 200.
		}
		else
		{
			y += jumpVelocity; //if not jumping do the same thing but add.
		}

		if (y >= dino->getDinoBottom()) //if the current yPos greater than 200-TheScaleOf the dino sprite in the Y
		//prevents lagging out and hitting top of window
		{
			onGround = true; //Dino must be on the ground
			y = dino->getDinoBottom();
		}

		if (y <= (dino->getDinoBottom() - 100))
		{
			jumping = false;
		}

		//generate random distance for the obstacle to approach from
		randomObsDist = rand() % 100;

		//send obstacles towards the player
		if (obstacleX <= 0) //if the obstacle is on the left of the screen
		{
			obstacleX = width + randomObsDist;
		}
		else
		{
			obstacleX -= obsVelocity;
		}

		/*check collision: */

		/*Box Collision which I wrote*/
		if (dino->getDinoSprite().getGlobalBounds().intersects(obs->getObsSprite().getGlobalBounds()))
		{
			gOver = true;
		}

		if (!gOver) //if not game over do all of these things
		{
			hud->updateHud();						   //keep tracking
			dino->dinoSetPosition(x, y);			   //set the position of the dinosaur
			obs->obsSetPosition(obstacleX, obstacleY); //set the postion of the dinosaur
		}
		else
		{
			//save->saveToFile(gOver);
			/* ./build.sh: line 71:   996 Segmentation fault      bin/$BUILD/$NAME $OPTIONS
			Error: Command "cmd_buildrun main" not recognized.
			The terminal process "C:\Program Files\Git\bin\bash.exe '-c',
			 'bash ./build.sh buildrun Debug vscode'" terminated with exit code: 1.
			*/
		}

		//Clear the window as white
		window->clear(Color::White);

		/*Static Objects First*/
		//Draw ground
		obj->drawGround(*window);

		/*Then Dynamic Objects*/
		//Draw obstacles
		obs->renderObs(*window, gOver);
		//Draw dino
		dino->renderDino(*window, gOver, onGround);

		hud->renderHud(*window, gOver);

		//show game elements on window
		window->display();
	}
}

/*


		//Pixel Pefect Collision wrote by Nick Koirala taken from the SFML wiki.
		//Requires namescpae collison , collision.cpp
		if (Collision::PixelPerfectTest(dino->getDinoSprite(), obs->getObsSprite()))
		{
			gOver = true;
		}

*/
