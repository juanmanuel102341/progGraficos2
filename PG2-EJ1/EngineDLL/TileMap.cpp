#include"TileMap.h"

TileMap::TileMap(Renderer* renderer) : Entity(renderer),currentIndex(0),lastWave(11) {
	cout << "********************inicio tilemap***********************" << endl;

}
void TileMap::MovingMap() {
	
		cout << "entrando " << endl;
		int index = 0;
		index = currentIndex * 30 * 10;
		for (int i = 0; i < 10; i++) {
			
	//		index += i * 30;


			gvertices[index] += 11 * ancho;//vertice esquina sup iquierda

			index += 5;

			gvertices[index] += 11 * ancho;//vertice esquina sup derecha


			index += 5;
			gvertices[index] += 11 * ancho;//vertice esquina inferior iquierda

			index += 5;
			//2do poligono
			gvertices[index] += 11 * ancho;//vertice esquina sup derecha

			index += 5;
			gvertices[index] += 11 * ancho;//vertice esquina inferior izquierda


			index += 5;
			gvertices[index] += 11 * ancho;//vertice esquina inferior derecha

			index += 5;
		}
		target += ancho;
		
		SetNewObjects();
		currentIndex++;
	
	
}
void TileMap::LoadExternalMap(string path,int sizeX,int sizeY) {
	char tile;
	std::fstream mapfile;
	mapfile.open(path);
	mapfile.get(tile);
	int indexRow = 0;
	int indexCol = 0;
	int cont = 0;
	cout << "***********archivo**********" << endl;
	while (mapfile>>tile)
	{
		if (tile != ',') {
			int num = tile-'0';
			aTiles[indexRow][indexCol] = num;
			if (indexCol >= SIZE_EXTERNAL_MAP_Y-1) {
				indexRow++;
				indexCol = 0;
				cout << "" << endl;
			}
			else {
				indexCol++;
			}
			cout <<" "<< cont<<") "<<num;
			cont++;
		}
	
	}
	for (int i = 0; i < SIZE_EXTERNAL_MAP_X; i++) {
		cout << "" << endl;
		for (int i2 = 0; i2 < SIZE_EXTERNAL_MAP_Y; i2++) {
			cout <<" "<< aTiles[i][i2];
		}
	}
	mapfile.close();
}
float* TileMap::getEntityValues(int index_i1,int index_i2) {
	float* aux = new float[30];
	int index=0;
	index = index_i2 * 10 * 30;
	index += index_i1 * 30;
	for (int i3 = 0; i3 < 30; i3++) {
		aux[i3] = gvertices[index + i3];
		//cout << i3;
		//cout << ")= " << gvertices[index + i3] << endl;
	}
	return aux;
}
void TileMap::SetNewObjects() {
	
	for (int i = 0; i < 10; i++) {
		if (aTiles[i][lastWave] == ENEMY_ID) {
			DataTiles* e = new DataTiles;
			e->idFrom = 3;
			e->idTo = 4;
			e->x = POS_MAP_X + lastWave*ancho - ancho;
			e->y = POS_MAP_Y - i*alto;
			dataEnemies.push_back(e);
			float* enemy;
			enemy = getEntityValues( i,currentIndex);
			enemiesValues.push_back(enemy);
		}
	}
	lastWave++;
}

void TileMap::Set() {
	int index=0;
	int indexPlayer = 0;
	cout << "************control set********" << endl;
	//cuidado la lectura es a la inveersa del seteo de los vertices 
	for (int i = 0; i < SIZE_TILE_MAP_Y; i++) {

		for (int i2 = 0; i2 < SIZE_TILE_MAP_X; i2++) {

			if (aTiles[i][i2] == PLAYER_ID) {
			
				dataPlayer.idFrom = 0;
				dataPlayer.idTo = 2;
				dataPlayer.x = POS_MAP_X + i2*ancho-ancho;
				dataPlayer.y = POS_MAP_Y - i*alto;
				//cout << "pos index " << index << endl;

				cout << "pos real player x" << dataPlayer.x<<endl;
				cout << "pos real player y" << dataPlayer.y << endl;
				playerValues = getEntityValues(i, i2);

				index = 0;
			}
			else if (aTiles[i][i2]==ENEMY_ID) {
				cout << "entrando enemy" << endl;
				DataTiles* e=new DataTiles;
				e->idFrom = 3;
				e->idTo = 4;
				e->x = POS_MAP_X + i2*ancho-ancho;
				e->y = POS_MAP_Y - i*alto;
				dataEnemies.push_back(e);
				float* enemy;
				enemy = getEntityValues(i, i2);
				enemiesValues.push_back(enemy);
				cout << "pos x enemy " << e->x<<endl;
				cout << "pos y enemy " << e->y << endl;
			}
			
		}
	}
}

float* TileMap::GetPlayerValues() {
	return playerValues;
}
void TileMap::Start() {
	
	ancho = 2;
	alto = 2;
	target = ancho;
	sizeMap = 3300;
	int id = 0;
	gvertices = new float[sizeMap];//11x10x5x6
	
	for (int i = 0; i < 11; i++) {
	
		for (int j = 0; j < 10; j++) {
			//1er vertice, esquina superior izquierda
		
				gvertices[id] = i*ancho;//x
				id++;
				gvertices[id] = -j*alto;//y
				id++;
				gvertices[id] = 0.0f;//z
				id++;
				//3er uvs
				gvertices[id] = 0.0f;
				id++;
				gvertices[id] = 1.0f;
				id++;
				//2do vertice, esquina superior derecha
				gvertices[id] = i*ancho + ancho;
				id++;
				gvertices[id] = -j*alto;
				id++;
				gvertices[id] = 0.0f;
				id++;
				//4to uvs
				gvertices[id] = 1.0f;
				id++;
				gvertices[id] = 1.0f;
				id++;
				//vertice esquina inferior izquierda
				gvertices[id] = i*ancho;
				id++;
				gvertices[id] = (-j*alto) - alto;
				id++;
				gvertices[id] = 0.0f;
				id++;
				// 1 er uvs
				gvertices[id] = 0.0f;
				id++;
				gvertices[id] = 0.0f;
				id++;
				//*****2do poligono*****
				//2do vertice, esquina superior derecha
				gvertices[id] = i*ancho + ancho;
				id++;
				gvertices[id] = -j*alto;
				id++;
				gvertices[id] = 0.0f;
				id++;
				//4to uvs
				gvertices[id] = 1.0f;
				id++;
				gvertices[id] = 1.0f;
				id++;
				//vertice esquina inferior izquierda
				gvertices[id] = i*ancho;
				id++;
				gvertices[id] = (-j*alto) - alto;
				id++;
				gvertices[id] = 0.0f;
				id++;
				// 1 er uvs
				gvertices[id] = 0.0f;
				id++;
				gvertices[id] = 0.0f;
				id++;
				// vertice esquina inferior derecha
				gvertices[id] = i*ancho + ancho;
				id++;
				gvertices[id] = (-j*alto) - alto;
				id++;
				gvertices[id] = 0.0f;
				id++;
				// 2do uvs
				gvertices[id] = 1.0f;
				id++;
				gvertices[id] = 0.0f;
				id++;
			}
			
		
	}
	
	//cout << "*********************entrando tilemap******************" << endl;
	LoadExternalMap("base_02.tmx",SIZE_EXTERNAL_MAP_X,SIZE_EXTERNAL_MAP_Y);
	playerValues = new float[30];
	Set();
}


void TileMap::Draw(){

}

void TileMap::Stop() {

}