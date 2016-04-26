
#pragma once

#include <Object.h>

#include <vector>


class Squad
{
public:
	Squad();
	~Squad();

	bool addAlly(yam2d::Object* _ally);
	bool addEnemy(yam2d::Object* _enemy);

protected:
	std::vector<yam2d::Object*> allies;
	std::vector<yam2d::Object*> enemies;
};
extern Squad* squad;

