#include"ImporterBmp.h"
DataBmp ImporterBmp::LoadTexture(const char* imagePath,Renderer* renderer ) {
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char* data;
	cout << "entrando bmp" << endl;
	
	FILE* file=fopen(imagePath,"rb");

	if (!file) {
		printf("image no se puede abrir");
		
	}
	printf("archivo se abre");
	if (fread(header, 1, 54, file)!=54) {
		printf("archivo bmp incorrecto");
	
	}
	printf("archivo bmp correcto 54");
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		
	}
	printf("archivo bmp correcto 54");
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (imageSize == 0) {
		imageSize = width*height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	}
	if (dataPos == 0) {
		dataPos = 54; // El encabezado del BMP está hecho de ésta manera
	}
	data = new unsigned char[imageSize];
	fseek(file, dataPos, 0);
	fread(data, 1, imageSize, file);
	fclose(file);
	unsigned int idTexture=renderer->GenTexture(width, height, data);
	
	DataBmp dataBmp;
	dataBmp.width = width;
	dataBmp.height = height;
	dataBmp.id = idTexture;
	cout << "width bmp " << dataBmp.width;
	cout << "height " << dataBmp.height;
	cout << "id texture " <<idTexture;
	return dataBmp;

	}
ImporterBmp::ImporterBmp(){

}