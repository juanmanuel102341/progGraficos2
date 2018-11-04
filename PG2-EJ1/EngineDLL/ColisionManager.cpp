#include"ColisionManager.h"
void ColisionManager::RegisterBoundingBox(BoundingBox* box,Group _group) {
	switch (_group)
	{
	case A:
		listGroupA.push_back(box);
		break;
	case B:
		listGroupB.push_back(box);
		break;
	}
}
bool ColisionManager::OnCheckCollision() {

	for (std::list<BoundingBox*>::iterator it = listGroupA.begin(); it != listGroupA.end(); it++) {
		BoundingBox* boxA = *it;
		for (std::list<BoundingBox*>::iterator it2 = listGroupB.begin(); it2 != listGroupB.end(); it2++) {
		BoundingBox* boxB = *it2;
		if (boxA->OnCollision(boxB)) {
			return true;
		}
		}
	}
	return false;
}

ColisionManager::ColisionManager() {

}