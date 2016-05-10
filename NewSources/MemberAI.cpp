
#include "MemberAI.h"

#include "Squad.h"
#include "GameApp.h"
#include "GameEvents.h"
#include "SearchNode.h"
#include "AStar.h"

#include "GameObject.h"


MemberAI::MemberAI(yam2d::GameObject* _owner, GameController* _gameController, BotType _botType) : CharacterController(_owner, _gameController, _botType), 
destDistance(0.0f), destination(nullptr)
{
	owner = _owner;
	type = _botType;
	controller = _gameController;
	squad->addAlly(this);

	if (isSoldier())
	{
		task = NADE;
	}
	else if (isRobot())
	{
		task = MINE;
	}
	else
	{
		//?
		assert(false);
	}
}
MemberAI::~MemberAI()
{
}


void MemberAI::onMessage(const std::string& _msgName, yam2d::Object* _eventObject)
{
	// Call onMessage to base class
	CharacterController::onMessage(_msgName, _eventObject);

	// TODO: handle message...
}


void MemberAI::update(float _deltaTime)
{
	// Call update to base class
	CharacterController::update(_deltaTime);

	switch (task)
	{
	case MINE:
		//Goto homebase and set mines
		tryDropMine(yam2d::vec2(1.0f));
		break;

	case NADE:
		//Throw grenade
		tryThrowGrenade(yam2d::vec2(1.0f));
		break;

	case DEFEND:
		//Fire at enemy from cover
		break;

	case ATTACK:
		//Fire aggressively at the enemy and advance
		break;

	case GETBOMB:
		//Retrieve the bomb
		break;

	case ANELE:
		//Run for the enemy base
		break;

	case REPOSITION:
		//Find new cover
		if (destination)
		{
			if (moveDirectToPosition(destination->pos.asconstslmvec(), 1.0f) < 0.1f)
			{
				if (destination->previous)
				{
					destination = destination->previous;
				}
			}
		}
		break;

	case DODGE:
		//Run away from fire
		break;

	default:
		break;
	}
}


void MemberAI::onGameStarted(GameEnvironmentInfoProvider* environmentInfo)
{

}


void MemberAI::onGameOver(GameEnvironmentInfoProvider* environmentInfo, const std::string& gameResultString)
{

}


void MemberAI::onUpdate(GameEnvironmentInfoProvider* environmentInfo, float deltaTime)
{
	if (destination == nullptr && squad->ready())
		destination = pathFinder->getPath(owner->getPosition(), squad->getHomeBasePosition(), environmentInfo);
}


void MemberAI::onGameEvent(GameEnvironmentInfoProvider* environmentInfo, const std::string& eventName, yam2d::Object* eventObject)
{

}


void MemberAI::onGameObjectEvent(GameEnvironmentInfoProvider* environmentInfo, yam2d::GameObject* gameObject, const std::string& eventName, yam2d::Object* eventObject)
{

}