#include"TileMap.h"

TileMap::TileMap() {
	gvertices = new float[64];
	int id = 0;
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			//1er vertice
			gvertices[id] = i*ancho;//x
			id++;
			gvertices[id] = j*alto;//y
			id++;
			gvertices[id] = 0;//z
			id++;
			//2do vertice
			gvertices[id] = i*ancho + ancho;
			id++;
			gvertices[id] = j*alto;
			id++;
			gvertices[id] = 0;
			//3er vertice
			gvertices[id] = i*ancho;
			id++;
			gvertices[id] = j*alto + alto;
			id++;
			gvertices[id] = 0;
			//4to vertice
			gvertices[id] = i*ancho + ancho;
			id++;
			gvertices[id] = j*alto + alto;
			id++;
			gvertices[id] = 0;



		}
	}

}