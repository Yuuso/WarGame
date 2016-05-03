
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

	if (squad == nullptr)
		squad = new Squad;

	squad->addAlly(owner);
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

	//Movement
	if (destination != nullptr)
	{
		if (moveDirectToPosition(destination->pos.asconstslmvec(), 0.0f) < 0.1f)
		{
			destination = destination->previous;
		}
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
		destination = pathFinder->getPath(owner->getPosition(), environmentInfo->getDynamite()->getPosition(), environmentInfo);
}


void MemberAI::onGameEvent(GameEnvironmentInfoProvider* environmentInfo, const std::string& eventName, yam2d::Object* eventObject)
{

}


void MemberAI::onGameObjectEvent(GameEnvironmentInfoProvider* environmentInfo, yam2d::GameObject* gameObject, const std::string& eventName, yam2d::Object* eventObject)
{

}