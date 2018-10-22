#pragma once
#pragma warning(disable : 4996)
#include "Exports.h"
#include<iostream>
#include<fstream>
#include"Renderer.h"
using namespace std;
struct DataBmp
{
	int width, height;
	unsigned int id;
};
class ENGINEDLL_API ImporterBmp
{
public:
	ImporterBmp();
	static DataBmp LoadTexture(const char* imagePath, Renderer* renderer);
	//static DataBmp dataBmp;

private:
	
	unsigned int textureId;
};

