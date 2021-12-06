#include "ActorArray.h"

void ActorArray::addActor(Actor* actor)
{
	//Create a new temp arary larger than the current one
	Actor** tempArray = new Actor * [m_actorCount + 1];

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

bool ActorArray::removeActor(Actor* actor)
{
	//Create a variable to store if the removal was successful
	bool actorRemoved = false;

	//Create a new temp arary smaller than the current one
	Actor** tempArray = new Actor * [m_actorCount - 1];

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

bool ActorArray::removeActor(int index)
{
	if (index < 0 || index >= m_actorCount)
		return false;

	//Create a variable to store if the removal was successful
	bool actorRemoved = false;

	//Create a new temp arary smaller than the current one
	Actor** tempArray = new Actor * [m_actorCount - 1];

	//Copy all values except the actor we dont want into the new array
	int j = 0;
	for (int i = 0; i < m_actorCount - 1; i++)
	{
		//If the actor that the loop is on is not the temp array counter
		if (i != index)
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

Actor* ActorArray::getActor(int index)
{
	if(index < 0 || index >= m_actorCount)
		return nullptr;

	return m_actors[index];
}

bool ActorArray::contains(Actor* actor)
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (m_actors[i] == actor)
			return true;
	}

	return false;
}
