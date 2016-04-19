
#pragma once

#include <Object.h>

#include <vector>


class Squad
{
public:
	Squad();
	~Squad();

protected:
	std::vector<yam2d::Object*> lastKnownPositions;
};

