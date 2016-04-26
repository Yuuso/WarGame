
#include "MemberAI.h"

#include "Squad.h"
#include "GameApp.h"
#include "GameEvents.h"


MemberAI::MemberAI(yam2d::GameObject* _owner, GameController* _gameController, BotType _botType) : CharacterController(_owner, _gameController, _botType)
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

	// TODO: Update...
}


void MemberAI::onGameStarted(GameEnvironmentInfoProvider* environmentInfo)
{

}


void MemberAI::onGameOver(GameEnvironmentInfoProvider* environmentInfo, const std::string& gameResultString)
{

}


void MemberAI::onUpdate(GameEnvironmentInfoProvider* environmentInfo, float deltaTime)
{
	
}


void MemberAI::onGameEvent(GameEnvironmentInfoProvider* environmentInfo, const std::string& eventName, yam2d::Object* eventObject)
{

}


void MemberAI::onGameObjectEvent(GameEnvironmentInfoProvider* environmentInfo, yam2d::GameObject* gameObject, const std::string& eventName, yam2d::Object* eventObject)
{

}