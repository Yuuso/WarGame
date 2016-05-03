
#pragma once

#include "Position.h"

#include <vector>
#include <string>


class AIMapLayer;
class SearchNode;

class SearchLevel
{
public:
	//AIMap = environmentInfo->getAILayer("GroundMoveSpeed");
	SearchLevel(AIMapLayer* _AIMap);
	~SearchLevel();

	float getG(SearchNode* _fromNode, const __vec2& _toPos) const;
	float getH(const __vec2& _fromPos, const __vec2& _toPos) const;

	bool isWalkable(const int _x, const int _y);

	std::vector<__vec2> getAdjacentNodes(const int _x, const int _y);

private:
	AIMapLayer* map;
};