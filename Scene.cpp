#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

bool Scene::getStarted()
{
	return false;
}

void Scene::addActor(Actor* actor)
{
	Actor** tempArray = new Actor* [m_actorCount];


}

bool Scene::removeActor(Actor* actor)
{
	return false;
}

void Scene::start()
{
}

void Scene::update()
{
}

void Scene::draw()
{
}

void Scene::end()
{
}
