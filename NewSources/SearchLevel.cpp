
#include "AIMapLayer.h"
#include "SearchLevel.h"
#include "SearchNode.h"


SearchLevel::SearchLevel(AIMapLayer* _AIMap) : map(_AIMap)
{
}
SearchLevel::~SearchLevel()
{
}


float SearchLevel::getG(SearchNode* _fromNode, const yam2d::vec2& _toPos) const
{
	float dx = (float) (_toPos.x - _fromNode->pos.x);
	float dy = (float) (_toPos.y - _fromNode->pos.y);
	return sqrt(dx*dx + dy*dy);
}


float SearchLevel::getH(const yam2d::vec2& _fromPos, const yam2d::vec2& _toPos) const
{
	float dx = (float) (_toPos.x - _toPos.x);
	float dy = (float) (_toPos.y - _toPos.y);
	return sqrtf(dx*dx + dy*dy);
}


bool SearchLevel::isWalkable(const int _x, const int _y)
{
	if (_x < 0 || _y < 0 || _x >= map->getWidth() || _y >= map->getHeight())
		return false;

	return map->getPixel(_x, _y)[0] != 0;
}


std::vector<yam2d::vec2> SearchLevel::getAdjacentNodes(const int _x, const int _y)
{
	std::vector<yam2d::vec2> result;
	if (isWalkable(_x + 1, _y))
		result.push_back(yam2d::vec2(_x + 1, _y));
	if (isWalkable(_x - 1, _y))
		result.push_back(yam2d::vec2(_x - 1, _y));
	if (isWalkable(_x, _y + 1))
		result.push_back(yam2d::vec2(_x, _y + 1));
	if (isWalkable(_x, _y - 1))
		result.push_back(yam2d::vec2(_x, _y - 1));
	return result;
}