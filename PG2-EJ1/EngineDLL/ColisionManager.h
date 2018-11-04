#pragma once
#include "Exports.h"
#include <iostream>
#include <list>
#include"BoundingBox.h"
using namespace std;
enum Group {
	A,B
};
class ENGINEDLL_API ColisionManager
{

public:
	 ColisionManager();
	 void RegisterBoundingBox(BoundingBox* bounding,Group group);
	 bool OnCheckCollision();
public :
	list<BoundingBox*>listGroupA;
	list<BoundingBox*>listGroupB;

private:

};
