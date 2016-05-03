
#pragma once

#include "vec2.h"

#include <vector>

class GameEnvironmentInfoProvider;
namespace yam2d { class GameObject; }

class Squad
{
public:
	Squad();
	~Squad();

	void setBomb(const yam2d::GameObject* _bomb);
	void setHomeBase(const yam2d::GameObject* _home);
	void setEnemyBase(const yam2d::GameObject* _enemy);

	bool addAlly(yam2d::GameObject* _ally);
	bool addEnemy(yam2d::GameObject* _enemy);

	const yam2d::vec2 getBombPosition();
	const yam2d::vec2 getHomeBasePosition();
	const yam2d::vec2 getEnemyBasePosition();

	bool ready();

protected:
	std::vector<yam2d::GameObject*> allies;
	std::vector<yam2d::GameObject*> enemies;
	const yam2d::GameObject* bomb;
	const yam2d::GameObject* enemyBase;
	const yam2d::GameObject* homeBase;
};
extern Squad* squad;

