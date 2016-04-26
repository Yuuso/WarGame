
#pragma once

#include <vector>
#include <string>
#include <vec2.h>


class AIMapLayer;
class SearchNode;

class SearchLevel
{
public:
	//AIMap = environmentInfo->getAILayer("GroundMoveSpeed");
	SearchLevel(AIMapLayer* _AIMap);
	~SearchLevel();

	float getG(SearchNode* _fromNode, const yam2d::vec2& _toPos) const;
	float getH(const yam2d::vec2& _fromPos, const yam2d::vec2& _toPos) const;

	bool isWalkable(const int _x, const int _y);

	std::vector<yam2d::vec2> getAdjacentNodes(const int _x, const int _y);

private:
	AIMapLayer* map;
};