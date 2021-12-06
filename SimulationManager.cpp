#include "SimulationManager.h"

bool SimulationManager::m_applicationShouldClose = false;
SimulationManager::SimulationManager()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

SimulationManager::~SimulationManager()
{
	delete m_currentFighter1;
	delete m_currentFighter2;
}

void SimulationManager::start()
{
	//initlize the entities
	Entity wompus = Entity('W', 100, 52, 15);
	Entity redactedBobRoss = Entity('r', 100, 60, 1);
	Entity unclePhil = Entity('U', 1, 20, 6955);
	//Sets the entities
	m_entities[0] = wompus;
	m_entities[1] = redactedBobRoss;
	m_entities[2] = unclePhil;
	m_entityCount = 3;

	/*int test = 5;
	Entity* entiyPtrs[5];
	Entity** entities = new Entity * [test];*/

	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void SimulationManager::update()
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
