
#include "ClosedList.h"
#include "SearchNode.h"


ClosedList::ClosedList()
{
}
ClosedList::~ClosedList()
{
}


void ClosedList::addToClosedList(SearchNode* _node)
{
	closedList[_node->pos] = _node;
}


bool ClosedList::isInClosedList(const __vec2& _pos) const
{
	return closedList.find(_pos) != closedList.end();
}


void ClosedList::clear()
{
	closedList.clear();
}


std::vector<SearchNode*> ClosedList::getClosedElements()
{
	std::vector<SearchNode*> result;
	for (auto &it : closedList)
	{
		result.push_back(it.second);
	}
	return result;
}