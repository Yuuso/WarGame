
#pragma once

#include "OpenList.h"
#include "ClosedList.h"
#include "SearchLevel.h"
#include "Position.h"

#include <vec2.h>
#include <vector>


class SearchNode;
class GameEnvironmentInfoProvider;
class AIMapLayer;

struct PathData
{
	PathData(AIMapLayer* _AIMap);
	~PathData();

	OpenList openList;
	ClosedList closedList;
	SearchLevel searchLevel;
	SearchNode* destination;
};

class AStar
{
public:
	AStar();
	~AStar();

	SearchNode* getPath(const yam2d::vec2& _start, const yam2d::vec2& _end, GameEnvironmentInfoProvider* _environmentInfo);

private:
	std::vector<PathData> paths;
};
extern AStar* pathFinder;