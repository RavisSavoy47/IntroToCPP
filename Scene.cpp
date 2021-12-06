#include "Scene.h"

Scene::Scene()
{
	m_actorCount = 0;
	m_actors[m_actorCount];
}

Scene::~Scene()
{
	delete[] m_actors;
}

bool Scene::getStarted()
{
	return false;
}

/// <summary>
/// Adds an actor to a scene
/// </summary>
void Scene::addActor(Actor* actor)
{
	//Create a new temp arary larger than the current one
	Actor** tempArray = new Actor* [m_actorCount + 1];

	//Copy all values from old array into the temp array
	for (int i = 0; i < m_actorCount; i++)
	{
		tempArray = m_actors;
	}

	//Add the new actor to the end of the new array
	tempArray[m_actorCount] = actor;

	//Set the old array to be the new array
	m_actors = tempArray;
	m_actorCount++;
}

/// <summary>
/// Removes an actor to a scene
/// </summary>
bool Scene::removeActor(Actor* actor)
{
	//Create a variable to store if the removal was successful
	bool actorRemoved = false;

	//Create a new temp arary smaller than the current one
	Actor** tempArray = new Actor* [m_actorCount - 1];

	//Copy all values except the actor we dont want into the new array
	int j = 0;
	for (int i = 0; i < m_actorCount - 1; i++)
	{
		//If the actor that the loop is on is not the temp array counter
		if (m_actors[i] != actor)
		{
			//..adds the actor into the new array and increments the tmep array counter
			tempArray[j] = m_actors[i];
			j++;
		}
		//Otherwise if the actor is the one to remove...
		else
		{
			//..set actorRemove to true
			actorRemoved = true;
		}		
	}
	//If the actorRemove was successful them
	if (actorRemoved)
		//Add the new array to the old array
		m_actors = tempArray;

	m_actorCount--;
	return actorRemoved;
}

/// <summary>
/// Removes an actor to a scene
/// </summary>
void Scene::start()
{
}

/// <summary>
/// Calls update for every actor in the scene. Calls start for the actor if it hasn't been called.
/// </summary>
void Scene::update()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (!m_started)
			m_actors[i]->start();

		m_actors[i]->update();
	}
}

/// <summary>
/// Draws the actors into the scene
/// </summary>
void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->draw;
	}
}

/// <summary>
/// Calles the actors end 
/// </summary>
void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->end;
	}
}
