#include"Avatar.h"
Avatar::Avatar(Renderer* renderer) :Sprite(renderer) {

	box = new BoundingBox();
}
void Avatar::StartAvatar() {
	Sprite::Start();
	box->SetValues(posX, posY, widthSprite, heightSprite);
}
void Avatar::StopAvatar() {
	Sprite::Stop();
	delete box;
	
}
void Avatar::UpdatePosition() {
	box->UpdatePosition(posX, posY);
}