
#include "OpenList.h"
#include "SearchNode.h"

#include <algorithm>


OpenList::OpenList()
{
}
OpenList::~OpenList()
{
}


SearchNode* OpenList::findFromOpenList(const __vec2& _pos) const
{
	for (auto &it : openList)
	{
		if (it->pos == _pos)
			return it;
	}
	return nullptr;
}


void OpenList::insertToOpenList(SearchNode* _node)
{
	openList.push_back(_node);
	sortOpenList();
}


void OpenList::sortOpenList()
{
	std::sort(openList.begin(), openList.end(), &SearchNode::lessThan);
}


SearchNode* OpenList::removeSmallestFromOpenList()
{
	SearchNode* result = *(openList.end() - 1);
	openList.pop_back();
	return result;
}


bool OpenList::isEmpty() const
{
	return openList.empty();
}


void OpenList::clear()
{
	openList.clear();
}