#include"Avatar.h"
Avatar::Avatar(Renderer* renderer) :Sprite(renderer), check(false), triguerEvent(false),mass(1){

	
}
void Avatar::SetObjectValues(ColisionState _colisionState, StateObject _state, float _mass) {
	collisionState= _colisionState;
	if (collisionState == boxCollider) {
		box = new BoundingBox();
		box->SetValues(posX, posY, widthSprite, heightSprite);
		if (_state == fijo) {
			box->state = StateObjectBox::fijoBox;
		}
		else if (_state == movil) {
			box->state = StateObjectBox::movilBox;
		}
		box->mass = _mass;
	}
	else if (collisionState == circleCollider) {
		circle = new BoundingCircle();
		circle->SetValues(posX, posY, widthSprite / 2);
		if (_state == fijo) {

			circle->state = StateObjectCircle::fijoCircule;
		}
		else if (_state == movil) {

			circle->state = StateObjectCircle::movileCircule;
		}
		else if (_state == trigger)
		{
			circle->state = StateObjectCircle::triggerCircle;
		}
	
		circle->mass = _mass;
	}
}

void Avatar::StartAvatar() {
	Sprite::Start();
	
	
}
void Avatar::StopAvatar() {
	Sprite::Stop();
	if (collisionState == boxCollider) {
		delete box;
	}
	else {
		delete circle;
	}
	
}

void Avatar::CheckCollision() {
	if (collisionState == boxCollider) {
		if (box->collide) {
			//	check = false;
			if (box->state == StateObjectBox::movilBox&&box->targetColision->state == StateObjectBox::movilBox) {
				float massTotal = mass + box->targetColision->mass;
				float myForce = 1 - mass / massTotal;
			//	cout << "mass total " << massTotal<<endl;
				//cout << "my force " << myForce<<endl;
				if (box->horizontal) {
				//	cout << "choque 2 moviles horizotal" << endl;
					//cout << "aplicando penetracion horizontal" << endl;
					//box->penX = 2;
					
					posX = posX + (box->penX*box->direction)*myForce;
					//SetPos(posX, posY, 0);
					box->collide = false;
					check = true;
					box->horizontal = false;
				//	cout << "direction " << box->direction << endl;
				//	cout << "penetracion x " << box->penX;
					
				}
				else {
					//cout << "choeque 2 moviles vertical" << endl;
					//box->penY =0.5f;
					posY = posY + (box->penY*box->direction)*myForce;
					//cout << "direction " << box->direction << endl;
					//cout << "penetracion y " << box->penY;
				//	SetPos(posX, posY, 0);
					box->collide = false;
					check = true;

				}
			}
			else if (box->state == StateObjectBox::movilBox&&box->targetColision->state == StateObjectBox::fijoBox) {
				//cout << "****chequeo fijo***" << endl;
				if (box->horizontal) {
					//cout << "choque horizontal" << endl;
					//box->penX = 0.5f;
					posX = posX + (box->penX*box->direction) * 1;
					//SetPos(posX, posY, 0);
					box->collide = false;
					check = true;
					box->horizontal = false;
					//cout << "direction " << box->direction << endl;
					//cout << "penetracion avatar x " << box->penX;

				}
				else {
					//vertical
					//cout << "*****chequeo vertical" << endl;
					//box->penY = 0.5f;
					posY = posY + (box->penY*box->direction) * 1;
					//cout << "direction " << box->direction << endl;
					//cout << "penetracion y " << box->penY;
					//SetPos(posX, posY, 0);
					box->collide = false;
					check = true;
				}
			}
		}
	}
	else {
		//circle collider
		if (circle->collide) {
			if (circle->state == StateObjectCircle::movileCircule&&circle->targetColision->state == StateObjectCircle::movileCircule) {
		//		cout << "*********chequeo movil ************" << endl;
			//	cout << "penetracion " <<circle->pen << endl;
				//cout << "direccion x" << circle->directionX;
				//cout << "direccion y" << circle->directionY;
				//circle->pen = 0.5;
				float massTotal = mass + circle->targetColision->mass;
				float myForce =1- mass / massTotal;
				posX = posX + circle->pen*circle->directionX*myForce;
				posY = posY + circle->pen*circle->directionY*myForce;
			//	SetPos(posX, posY,0);
				circle->collide = false;
				check = true;
				//cout << "mass total " << massTotal<<endl;
				//cout << "my force " << myForce<<endl;
			
			}
			else if (circle->state == StateObjectCircle::movileCircule&&circle->targetColision->state == StateObject::fijo) {
				//	cout << "**********chequeo fijo target*************" << endl;
					//cout << "moviendo solamente circle movil" << endl;
				//	circle->pen = 0.5f;
					posX = posX + circle->pen*circle->directionX * 1;
					posY = posY + circle->pen*circle->directionY * 1;
					posX = posX + 0.002f*circle->directionX;
					posY = posY + 0.002f * circle->directionY;
			//		SetPos(posX, posY, 0);
					circle->collide = false;
					check = true;
			
			}
			else if(circle->state==StateObjectCircle::triggerCircle&&circle->targetColision->state==StateObjectCircle::triggerCircle&&!triguerEvent||
				circle->state==StateObjectCircle::triggerCircle&&circle->targetColision->state==StateObjectCircle::fijoCircule&&!triguerEvent) {
				
				//cout << "***************triguer event****************" << endl;
				circle->collide = false;
				check = true;
				triguerEvent = true;
			}
				
		}
	

	}
}
void Avatar::UpdatePosition() {
	if (collisionState == boxCollider) {
		box->UpdatePosition(posX, posY);
	}
	else if(collisionState==circleCollider) {
		circle->UpdatePosition(posX, posY);
	}
	CheckCollision();
}