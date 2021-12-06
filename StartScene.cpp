#include "StartScene.h"
#include "Engine.h"
#include <iostream>
void StartScene::draw()
{
	//system("cls");
	std::cout << "Welcome To the Game! \nWould you to play the game?" << std::endl;
}

void StartScene::update()
{
	char playerInput = '\0';
	bool invalidInput = true;

	while (!invalidInput)
	{
		std::cout << "1. Start Similation \n 2. Close Application" << std::endl;
		std::cin >> playerInput;

		if (playerInput == 1)
		{

		}
		if(playerInput == 2)
		{
			Engine::setApplicationShouldClose(true);
		}

	}
}
