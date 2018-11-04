#include"BoundingBox.h"
void BoundingBox::SetValues(float _x, float _y, int _widht, int _height) {
	x = _x;
	y = _y;
	BoundingWidht = _widht;
	boundingHeight = _height;
}
void BoundingBox::UpdatePosition(float _x, float _y) {
	x = _x;
	y = _y;
}
bool BoundingBox::OnCollision(BoundingBox* boxB){
	float deltaX=0;
	float deltaY=0;
	deltaX = abs(boxB->x- x);
	deltaY = abs(boxB->y - y);
	if (deltaX < BoundingWidht / 2 + boxB->BoundingWidht / 2 && deltaY < boundingHeight / 2 + boxB->boundingHeight / 2) {
		cout << "colision !" << endl;
		boxB->collide = true;
		collide = true;
		return true;
	}
	return false;
}
BoundingBox::BoundingBox():collide(false){

}