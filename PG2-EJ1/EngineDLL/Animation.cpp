#include"Animation.h"

Animation::Animation() {

}
void Animation::SetAnimation(Avatar* _avatar, int _idFrom, int _idTo,bool _repeat) {
	DataAnimation* data = new DataAnimation;
	data->avatar = _avatar;
	data->idFrom = _idFrom;
	data->idTo = _idTo;
	data->timing = 0;
	data->index = _idFrom-1;
	data->avatar->SetFrame(data->idFrom);
	data->repeat = _repeat;
	data->oneShoot = false;
	listDataAnimation.push_back(data);
	
}
void Animation::Update(double time){
	

	for (std::list<DataAnimation*>::iterator it = listDataAnimation.begin(); it != listDataAnimation.end(); it++) {
		DataAnimation* data=*it;
		if (data->repeat || data->oneShoot == false) {
			data->timing += time;
			// cout << "time elapsed" <<timing  << endl;
			if (data->timing > frameRate) {
				if (data->index < data->idTo) {
					data->index++;
					data->avatar->SetFrame(data->index);
					data->timing = 0;
					//cout << "cambio de frame " << data->index << endl;
				}
				else {
					//cout << "paso el limite cambiando frame" << endl;
					if (data->repeat ) {
						data->index = data->idFrom;
						data->avatar->SetFrame(data->index);
					}
					data->timing = 0;
					data->oneShoot = true;
				}
			}
		}
	}
}
