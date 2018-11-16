#include"ColisionManager.h"
void ColisionManager::RegisterBoundingBox(BoundingBox* box,Group _group) {
	switch (_group)
	{
	case A:
		listGroupABox.push_back(box);
		break;
	case B:
		listGroupBBox.push_back(box);
		break;
	}
}
void ColisionManager::RegisterBoundingCircle(BoundingCircle* circle, Group _group) {
	switch (_group)
	{
	case A:
		listGroupACircle.push_back(circle);
		break;
	case B:
		listGroupBCircle.push_back(circle);
		break;
	
	}
}
bool ColisionManager::OnCheckCollisionBox() {

	for (std::list<BoundingBox*>::iterator it = listGroupABox.begin(); it != listGroupABox.end(); it++) {
		BoundingBox* boxA = *it;
		for (std::list<BoundingBox*>::iterator it2 = listGroupBBox.begin(); it2 != listGroupBBox.end(); it2++) {
		BoundingBox* boxB = *it2;
		if (boxA->OnCollision(boxB)) {
		
			return true;
		}
		}
	}

	return false;
}
bool ColisionManager::OnCheckCollisionCircle() {
	for (std::list<BoundingCircle*>::iterator it = listGroupACircle.begin(); it != listGroupACircle.end(); it++) {
		BoundingCircle*		circleA = *it;
		for (std::list<BoundingCircle*>::iterator it2 = listGroupBCircle.begin(); it2 != listGroupBCircle.end(); it2++) {
			BoundingCircle* circleB = *it2;
			if (circleA->OnCollision(circleB)) {

				return true;
			}
		}
	}
	return false;
}

ColisionManager::ColisionManager() {

}