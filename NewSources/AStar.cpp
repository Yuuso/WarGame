
#include "AStar.h"
#include "SearchNode.h"
#include "GameEnvironmentInfoProvider.h"
#include "AIMapLayer.h"


PathData::PathData(AIMapLayer* _AIMap) : searchLevel(_AIMap), destination(nullptr)
{
}
PathData::~PathData()
{
}


AStar* pathFinder;

AStar::AStar()
{

}
AStar::~AStar()
{

}

SearchNode* AStar::getPath(const yam2d::vec2& _start, const yam2d::vec2& _end, GameEnvironmentInfoProvider* _environmentInfo)
{
	PathData data(_environmentInfo->getAILayer("GroundMoveSpeed"));
	std::vector<__vec2> adjacentNodes;

	data.openList.insertToOpenList(new SearchNode(_start, data.searchLevel.getH(_start, _end), 0, nullptr));

	while (!data.openList.isEmpty())
	{
		SearchNode* S = data.openList.removeSmallestFromOpenList();
		if (S->pos == _end)
		{
			data.destination = S;
			break;
		}
		else
		{
			data.closedList.addToClosedList(S);

			adjacentNodes = data.searchLevel.getAdjacentNodes(S->pos.x, S->pos.y);
			for (unsigned i = 0; i < adjacentNodes.size(); i++)
			{
				if (data.closedList.isInClosedList(adjacentNodes[i]))
					continue;

				SearchNode* node = data.openList.findFromOpenList(adjacentNodes[i]);
				if (node == nullptr)
				{
					data.openList.insertToOpenList(new SearchNode(adjacentNodes[i], data.searchLevel.getH(adjacentNodes[i], _end), data.searchLevel.getG(S, adjacentNodes[i]), S));
				}
				else
				{
					SearchNode newNode(adjacentNodes[i], data.searchLevel.getH(adjacentNodes[i], _end), data.searchLevel.getG(S, adjacentNodes[i]), S);
					if (node->getDistance() < newNode.getDistance())
					{
						node->resetPrev(newNode.previous, data.searchLevel.getG(newNode.previous, node->pos));
					}
				}
			}
		}
	}

	return data.destination;
}