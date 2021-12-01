#include "Engine.h"

bool Engine::m_applicationShouldClose = false;
Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
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
	//initlize the entities
	Entity wompus = Entity('W', 130003000, 5780002, -15000);
	Entity redactedLittleSkeleton = Entity('r', 440000 - 4400, -40, 0);
	Entity unclePhil = Entity('U', 1, 50, 6900055);
	//Sets the entities
	m_entities[0] = wompus;
	m_entities[1] = redactedLittleSkeleton;
	m_entities[2] = unclePhil;

	m_currentFighter1 = m_entities[0];
	m_currentFighter2 = m_entities[1];
	m_currentFighterIndex = 2;
}

void Engine::update()
{

	//Checked death
	m_currentFighter1.attack(m_currentFighter2);
	m_currentFighter2.attack(m_currentFighter1);

	
}

void Engine::draw()
{

}

void Engine::end()
{

}
