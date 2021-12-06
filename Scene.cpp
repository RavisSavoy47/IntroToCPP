#include "Scene.h"

Scene::Scene()
{
	m_actorCount = 0;
	m_actors = ActorArray();
}

Scene::~Scene()
{
	
}

bool Scene::getStarted()
{
	return m_started;
}

/// <summary>
/// Adds an actor to a scene
/// </summary>
void Scene::addActor(Actor* actor)
{
	return m_actors.addActor(actor);
}

/// <summary>
/// Removes an actor to a scene
/// </summary>
bool Scene::removeActor(Actor* actor)
{
	return m_actors.removeActor(actor);
}

/// <summary>
/// Removes an actor to a scene
/// </summary>
void Scene::start()
{
}

/// <summary>
/// Calls update for every actor in the scene. Calls start for the actor if it hasn't been called.
/// <summary>
void Scene::update()
{
	for (int i = 0; i < m_actors.getLength; i++)
	{
		if (m_actors.getActor(i)->getStarted())
			m_actors.getActor(i)->start();

		m_actors.getActor(i)->update();
	}
}

/// <summary>
/// Draws the actors into the scene
/// </summary>
void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->draw();
	}
}

/// <summary>
/// Calles the actors end 
/// </summary>
void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
	{
		m_actors[i]->end();
	}
}
