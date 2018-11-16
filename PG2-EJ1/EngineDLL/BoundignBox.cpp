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
		targetColision = boxB;
		boxB->targetColision = this;

		penX = BoundingWidht / 2 + boxB->BoundingWidht / 2 - deltaX;
		penY = boundingHeight / 2 + boundingHeight / 2 - deltaY;
		boxB->penX = boxB->BoundingWidht / 2 + BoundingWidht / 2 - deltaX;
		boxB->penY = boxB->boundingHeight / 2 + boundingHeight / 2 - deltaY;
		if (penX > penY) {
			//vertical
			cout << "boundign vertical " << endl;
			horizontal = false;
			boxB->horizontal = false;
			if (boxB->y>y) {
				boxB->direction = 1;
				direction =- 1;
			}
			else {
			//box b abajo
			boxB->direction = -1;
			direction = 1;
			}
		}
		else
		{
			cout << "**********choque horizontal*******" << endl;
			horizontal = true;
			boxB->horizontal = true;
			if (boxB->x>x) {
			//bounding b viene de la derecha
				cout << "bounding b viene de la derecha " << endl;
				boxB->direction = 1;
				direction = -1;
				cout << "direction objeto base" << direction<<endl;
				cout << "direction objeto b" << boxB->direction << endl;
				cout << "penetracion x " << penX<<endl;
			}
			else {
				
				cout << "bounding b viene de la  izquierda "<<endl;
				boxB->direction = -1;
				direction = 1;
				//cout << "direction objeto base" << direction<<endl;
				cout << "direction objeto b" << boxB->direction << endl;
			}
		}
		boxB->collide = true;
		collide = true;

		return true;
	}
	return false;
}
BoundingBox::BoundingBox() :collide(false), penX(0), penY(0), horizontal(false),targetColision(nullptr),mass(1) {

}