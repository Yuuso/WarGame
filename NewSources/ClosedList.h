
#pragma once

#include <vec2.h>

#include <map>
#include <vector>


class SearchNode;

class ClosedList
{
public:
	ClosedList();
	~ClosedList();

	void addToClosedList(SearchNode* _node);
	bool isInClosedList(const yam2d::vec2& _pos) const;
	void clear();
	std::vector<SearchNode*> getClosedElements();

private:
	typedef std::map<yam2d::vec2, SearchNode*> ClosedListType;
	ClosedListType closedList;

};