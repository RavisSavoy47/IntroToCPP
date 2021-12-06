#include "Engine.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;
Engine::Engine()
{
	m_applicationShouldClose = false;
	
}

Engine::~Engine()
{
	
}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		update();
		draw();
	}

	end();
}

void Engine::start()
{
	
	
}

void Engine::update()
{
	
}

//Draws the fighters
void Engine::draw()
{
	//m_currentFighter1->printStats();
	//m_currentFighter2->printStats();
	system("pause");
	system("cls");
}

void Engine::end()
{

}
