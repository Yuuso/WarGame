
#pragma once

#include "Position.h"

#include <map>
#include <vector>


class SearchNode;

class ClosedList
{
public:
	ClosedList();
	~ClosedList();

	void addToClosedList(SearchNode* _node);
	bool isInClosedList(const __vec2& _pos) const;
	void clear();
	std::vector<SearchNode*> getClosedElements();

private:
	typedef std::map<__vec2, SearchNode*> ClosedListType;
	ClosedListType closedList;
};