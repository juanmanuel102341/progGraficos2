#pragma once
#include "Exports.h"

class ENGINEDLL_API TileMap
{
public:
	//tiene q hereadar de entity
	TileMap();
	//~TileMap();

private:
	float* gvertices;
	float ancho;
	float alto;
};
