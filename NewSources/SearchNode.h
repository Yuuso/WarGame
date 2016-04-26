
#pragma once

#include <vec2.h>


class SearchNode
{
public:
	SearchNode(const yam2d::vec2& _currentPos, const float _H, const float _deltaG, SearchNode* _previous);
	~SearchNode();

	void resetPrev(SearchNode* _previous, const float _deltaG);
	float getDistance() const;

	static bool lessThan(SearchNode* _n1, SearchNode* _n2);

	SearchNode* previous;
	yam2d::vec2 pos;
	float G, H, F;
};