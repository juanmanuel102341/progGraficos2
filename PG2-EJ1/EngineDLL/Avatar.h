#pragma once

#include"Sprite.h"
#include"BoundingBox.h"
class ENGINEDLL_API Avatar: public Sprite
{
public:

	Avatar(Renderer* renderer);
	void StartAvatar();
	void StopAvatar();
	void UpdatePosition();
	BoundingBox* box;
private:
	
};
