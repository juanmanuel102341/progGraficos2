#pragma once

#include"Sprite.h"
#include"BoundingBox.h"
#include"BoundingCircle.h"
enum ColisionState {
	boxCollider, circleCollider
};
enum StateObject {
	fijo, movil,trigger
};
class ENGINEDLL_API Avatar: public Sprite
{
public:

	Avatar(Renderer* renderer);
	void StartAvatar();
	void StopAvatar();
	void UpdatePosition();
	void CheckCollision();
	BoundingBox* box;
	BoundingCircle* circle;

	void SetObjectState(StateObject state);
	void SetCollisionState(ColisionState colisionState);
	void SetMass(float _mass);
	bool check;
	bool triguerEvent;
private:
	ColisionState collisionState;
	float mass;
	//StateObject state;
};
