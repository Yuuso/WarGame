
#pragma once

#include <vec2.h>
#include <vector>


class SearchNode;

class OpenList
{
public:
	OpenList();
	~OpenList();

	SearchNode* findFromOpenList(const yam2d::vec2& _pos) const;
	void insertToOpenList(SearchNode* _node);
	void sortOpenList();
	SearchNode* removeSmallestFromOpenList();
	bool isEmpty() const;
	void clear();

private:
	typedef std::vector<SearchNode*> OpenListType;
	OpenListType openList;
};