#pragma once
#include "Exports.h"
#include <iostream>
#include <list>
#include"BoundingBox.h"
#include"BoundingCircle.h"
using namespace std;
enum Group {
	A,B
};
class ENGINEDLL_API ColisionManager
{

public:
	 ColisionManager();
	 void RegisterBoundingBox(BoundingBox* bounding,Group group);
	 void RegisterBoundingCircle(BoundingCircle* bounding, Group group);
	 
	 bool OnCheckCollisionBox();
	 bool OnCheckCollisionCircle();
public :
	list<BoundingBox*>listGroupABox;
	list<BoundingBox*>listGroupBBox;
	list<BoundingCircle*>listGroupACircle;
	list<BoundingCircle*>listGroupBCircle;
private:

};
