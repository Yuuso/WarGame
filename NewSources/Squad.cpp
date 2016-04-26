
#include "Squad.h"
#include "AStar.h"


Squad* squad = nullptr;

Squad::Squad()
{
	if (pathFinder == nullptr)
		pathFinder = new AStar;
}
Squad::~Squad()
{
}


bool Squad::addAlly(yam2d::Object* _ally)
{
	for (unsigned i = 0; i < allies.size(); i++)
	{
		if (allies[i] == _ally)
		{
			return false;
		}
	}
	allies.push_back(_ally);
	return true;
}


bool Squad::addEnemy(yam2d::Object* _enemy)
{
	for (unsigned i = 0; i < enemies.size(); i++)
	{
		if (enemies[i] == _enemy)
		{
			return false;
		}
	}
	enemies.push_back(_enemy);
	return true;
}