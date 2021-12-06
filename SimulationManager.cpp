#include "SimulationManager.h"
#include "Engine.h"
#include <iostream>

SimulationManager::SimulationManager()
{
	Engine::setApplicationShouldClose(false);
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
		Engine::setApplicationShouldClose(true);
		return;
	}

	m_currentFighter1->attack(m_currentFighter2);
	m_currentFighter2->attack(m_currentFighter1);
}

void SimulationManager::draw()
{
	m_currentFighter1->printStats();
	m_currentFighter2->printStats();
	system("pause");
	system("cls");
}
