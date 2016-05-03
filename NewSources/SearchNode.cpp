
#include "SearchNode.h"


SearchNode::SearchNode(const __vec2& _currentPos, const float _H, const float _deltaG, SearchNode* _previous) : previous(nullptr), pos(_currentPos), G(0.0f), H(_H), F(0.0f)
{
	resetPrev(_previous, _deltaG);
}
SearchNode::~SearchNode()
{
}


void SearchNode::resetPrev(SearchNode* _previous, const float _deltaG)
{
	previous = _previous;
	if (previous == nullptr)
		G = 0.0f;
	else
		G = _deltaG + _previous->G;

	F = G + H;
}


float SearchNode::getDistance() const
{
	return F;
}


bool SearchNode::lessThan(SearchNode* _n1, SearchNode* _n2)
{
	return _n1->getDistance() > _n2->getDistance();
}