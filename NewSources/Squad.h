
#pragma once

#include "vec2.h"

#include <vector>

class GameEnvironmentInfoProvider;
class PlayerController;
class MemberAI;
namespace yam2d { class GameObject; }

class Squad
{
public:
	Squad();
	Squad(PlayerController* _creator);
	~Squad();

	void setBomb(const yam2d::GameObject* _bomb);
	void setHomeBase(const yam2d::GameObject* _home);
	void setEnemyBase(const yam2d::GameObject* _enemy);
	bool confirmBases();

	bool addAlly(MemberAI* _ally);
	bool addEnemy(yam2d::GameObject* _enemy);
	void addMine(yam2d::vec2 _position);

	std::vector<MemberAI*>& getAllies();
	std::vector<yam2d::GameObject*>& getEnemies();
	std::vector<yam2d::vec2>& getMines();
	PlayerController* getCreator();

	const yam2d::vec2 getBombPosition();
	const yam2d::vec2 getHomeBasePosition();
	const yam2d::vec2 getEnemyBasePosition();

	bool ready();

protected:
	std::vector<MemberAI*> allies;
	std::vector<yam2d::GameObject*> enemies;
	std::vector<yam2d::vec2> mines;
	const yam2d::GameObject* bomb;
	const yam2d::GameObject* enemyBase;
	const yam2d::GameObject* homeBase;
	PlayerController* creator;
};
extern Squad* squad;

