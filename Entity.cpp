#include "Entity.h"

//Include entity constructor and includes a defenition
Entity::Entity(char icon, float health, float attackPower, float defensePower)
{
	m_icon = icon;
	m_health = health;
	m_attackPower = attackPower;
	m_defensePower = defensePower;
}

//Gets the damage that was taken
float Entity::takeDamage(float damageAmount)
{
	float damageTaken = damageAmount - getDefensePower();

	if (damageTaken < 0)
		damageTaken = 0;

	m_health -= damageTaken;

	if (m_health < 0)
		m_health = 0;

	return damageTaken;
}

//Returns the damage by the attack power
float Entity::attack(Entity entity)
{
	return entity.takeDamage(getAttackPower());
}
