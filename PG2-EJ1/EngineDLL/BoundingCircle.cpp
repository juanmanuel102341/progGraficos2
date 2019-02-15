#include"BoundingCircle.h"

BoundingCircle::BoundingCircle():mass(1){

}
void BoundingCircle::SetValues(float _x, float _y, float _radius){
	x = _x;
	y = _y;
	radius = _radius;
}
void BoundingCircle::UpdatePosition(float _x, float _y) {
	x = _x;
	y = _y;
}
bool BoundingCircle::OnCollision(BoundingCircle* circleB) {
	float diffX;
	float diffY;
	float deltaX = 0;
	float deltaY = 0;
	float distSqrX = 0;
	float distSqrY = 0;
	float distSqr=0;
	float sumRadius=0;
	float powRadius=0;
	float distance=0;
	diffX = circleB->x - x;
	diffY = circleB->y - y;
	deltaX = abs(diffX);
	deltaY = abs(diffY);
	distSqrX = pow(deltaX, 2.0);
	distSqrY = pow(deltaY, 2.0);
	distSqr = distSqrX + distSqrY;
	sumRadius = radius + circleB->radius;
	powRadius = pow(sumRadius, 2.0);
	//cout << "ditancia sqr " << distSqr << endl;
	//cout << "powradius " << powRadius << endl;
	if (distSqr < powRadius) {
		//cout << "contacto circle" << endl;
		distance = sqrt(distSqr);
		pen = sumRadius - distance;
		
		circleB->directionX = diffX / distance;
		circleB->directionY = diffY / distance;
		directionX = circleB->directionX*-1;
		directionY= circleB->directionY*-1;

		targetColision = circleB;
		circleB->targetColision = this;
		collide = true;
		circleB->collide = true;
		//cout << "direction x " << directionX;
		//cout << "direction y " << directionY;
		//cout << "distance " << distance << endl;
		//cout << "penetracion " << pen;
		return true;
	}
	return false;

}