#pragma once
#include "Exports.h"
#include"Entity.h"
#include<string>
#include<fstream>
#include"ImporterBmp.h"
#include<vector>
using namespace std;
const int SIZE_EXTERNAL_MAP_X = 10;
const int SIZE_EXTERNAL_MAP_Y = 13;
const int SIZE_TILE_MAP_X = 11;
const int SIZE_TILE_MAP_Y = 10;
const int PLAYER_ID = 1; 
const int ENEMY_ID = 2;
const int ASTEROID_ID = 3;
struct DataTiles
{
	int idFrom;
	int idTo;
	int x, y;
};
class ENGINEDLL_API TileMap: public Entity
{
public:
	//tiene q hereadar de entity
	TileMap(Renderer* renderer);
	//~TileMap();
	void Start() override;
	void Stop()override;
	void Draw()override;
	void LoadExternalMap(string path,int sizeX,int SizeY);
	float* GetPlayerValues();
	void MovingMap();

public:
	float* playerValues;
	vector<float*>enemiesValues;
	vector<float*>asteroidsValues;

	DataTiles* dataPlayer;
	vector<DataTiles*> dataEnemies;
	vector<DataTiles*> dataAsteroids;
	float target;
private:
	void Set();
	float* getEntityValues(int index_i,int index_c);
	void SetNewObjects();
	DataTiles* GenerateDataTiles(int index_i, int index_i2, int from, int to);

	//float* NewEnemy(int i, int i2);
private:
	int sizeMap;
	int aTiles[10][13];
	float ancho;
	float alto;
	int widthFrame;
	int heightFrame;
	float x, y;
	DataBmp data;
	ImporterBmp importBmp;
	float* gvertices;
	int currentIndex;
	int lastWave;

	
};
