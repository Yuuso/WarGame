
#pragma once

#include "PlayerController.h"


class Squad;
class SearchNode;

class MemberAI : public CharacterController
{
public:
	MemberAI(yam2d::GameObject* _owner, GameController* _gameController, BotType _botType);
	virtual ~MemberAI();

	virtual void onMessage(const std::string& msgName, yam2d::Object* eventObject);

	// This virtual method is automatically called by map/layer, when update is called from main.cpp
	virtual void update(float deltaTime);

	// Called, when bots have spawn. Can be used some custom initialization after spawn.
	void onGameStarted(GameEnvironmentInfoProvider* environmentInfo);

	// Called when game has ended. Can be used some cuystom deinitialization after game.
	void onGameOver(GameEnvironmentInfoProvider* environmentInfo, const std::string& gameResultString);

	// Called each frame. Update you player character controllers in this function.
	void onUpdate(GameEnvironmentInfoProvider* environmentInfo, float deltaTime);

	// Called, when game event has ocurred.
	// Event name tells the event in question, each event type may have eventObject data associated with the event.
	// 
	// Currently supported eventNames and eventObject data desctiption:
	// - ObjectSpawned:
	//		Called when new object is spawned to the level.
	//		eventObject: yam2d::GameObject* = object which was spawn.
	// - ObjectDeleted:
	//		Called when object is deleted from the level.
	//		eventObject: yam2d::GameObject* = object which is going to be deleted.
	// - ItemPicked: 
	//		Called when item has beed picked by game object.
	//		eventObject: ItemPickedEvent* = Item picked event
	// - ItemDropped: 
	//		Called when item has beed dropped by game object.
	//		eventObject: ItemDropperdEvent* = Item dropped event
	void onGameEvent(GameEnvironmentInfoProvider* environmentInfo, const std::string& eventName, yam2d::Object* eventObject);

	// Send, when game object receives an event.
	// Event name tells the event in question, each event type may have eventObject data associated with the event.
	//
	// Currently supported eventNames and eventObject data desctiption:
	// - Collision: 
	//		Called when game object collides to another object. 
	//		eventObject: CollisionEvent* = Information about collision.
	// - TakingDamage:
	//		Called when game object is taking damage.
	//		eventObject: yam2d::GameObject* = object which give damage to the object. Typically this is bullet, missile, mine or grenade etc.
	// - ZeroHealth: 
	//		Called when game object is going to die, because of zero health.
	//		eventObject: 0 always.
	void onGameObjectEvent(GameEnvironmentInfoProvider* environmentInfo, yam2d::GameObject* gameObject, const std::string& eventName, yam2d::Object* eventObject);

private:

	yam2d::GameObject* owner;
	BotType type;
	GameController* controller;

	float destDistance;
	SearchNode* destination;
};

