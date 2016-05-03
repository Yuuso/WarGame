
#include "Squad.h"
#include "AStar.h"

#include "GameObject.h"
#include "GameEnvironmentInfoProvider.h"


Squad* squad = nullptr;

Squad::Squad() : bomb(nullptr), homeBase(nullptr), enemyBase(nullptr)
{
	if (pathFinder == nullptr)
		pathFinder = new AStar;
}
Squad::~Squad()
{
}


void Squad::setBomb(const yam2d::GameObject* _bomb)
{
	bomb = _bomb;
}
void Squad::setHomeBase(const yam2d::GameObject* _home)
{
	homeBase = _home;
}
void Squad::setEnemyBase(const yam2d::GameObject* _enemy)
{
	enemyBase = _enemy;
}


bool Squad::addAlly(yam2d::GameObject* _ally)
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


bool Squad::addEnemy(yam2d::GameObject* _enemy)
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


const yam2d::vec2 Squad::getBombPosition()
{
	return bomb->getPosition();
}
const yam2d::vec2 Squad::getHomeBasePosition()
{
	return homeBase->getPosition();
}
const yam2d::vec2 Squad::getEnemyBasePosition()
{
	return enemyBase->getPosition();
}


bool Squad::ready()
{
	if (bomb && homeBase && enemyBase)
		return true;
	return false;
}