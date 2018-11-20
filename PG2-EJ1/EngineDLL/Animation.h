#pragma once
#include "Avatar.h"
#include<list>
const float frameRate = 0.7f ;
struct DataAnimation
{
	int idFrom, idTo,index;
	Avatar*avatar;
	double timing;
	bool repeat;
	bool oneShoot;
};
class ENGINEDLL_API Animation
{
public:
	Animation();
	void Update(double time);
	void SetAnimation(Avatar* avatar, int idFrom, int idTo,bool repeat);
private:
	list<DataAnimation*>listDataAnimation;
	
	int index = 0;
};

