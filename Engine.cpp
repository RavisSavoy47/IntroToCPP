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
	Entity wompus = Entity('W', 13000, 52, -15000);
	Entity redactedBobRoss = Entity('r', 440000 - 4400, 60, 0);
	Entity unclePhil = Entity('U', 1, 150, 6900055);
	//Sets the entities
	m_entities[0] = wompus;
	m_entities[1] = redactedBobRoss;
	m_entities[2] = unclePhil;
	m_entityCount = 3;

	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void Engine::update()
{
	//Checks if fighter 1 died
	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter1 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	//Chceks if fighter 2 died
	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter2 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	//Checks if both fighters died at the and if the index is higher than the entity count
	if (m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_applicationShouldClose = true;
		return;
	}

	m_currentFighter1->attack(m_currentFighter2);
	m_currentFighter2->attack(m_currentFighter1);
}

void Engine::draw()
{

}

void Engine::end()
{

}
