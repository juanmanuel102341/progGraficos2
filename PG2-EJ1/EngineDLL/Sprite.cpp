#include"Sprite.h"

void Sprite::Stop(){
}
void Sprite::Start() {
	gvertices = new float[32]
	{	
		-1.0f, 1.0f, 0.0f,
		1.0f,0.0f,0.0f,//color
		0.0f,1.0f,//uv esquina superior izquierda
	
		1.0f,  1.0f, 0.0f,
		0.0f,1.0f,0.0f,//color
		1.0f,1.0f,//uv esquina superior derecha
		
		-1.0f, -1.0f, 0.0f,
		0.0f,0.0f,1.0f,//color
		0.0f,0.0f,// uv esquina inferior izquierda
		
		1.0f, -1.0f, 0.0f,
		1.0f,0.0f,0.0f,//color
		1.0f,0.0f,//uv esquina inferior derecha
	};
	int size = sizeof(float) * 32;
	vertexBuffer = renderer->SetBufferData(gvertices, size);
	numberOfVertices = 4;
	primitive = strip;
	applyUv = true;
	tam = 8;
	widthSprite = abs(gvertices[8] - gvertices[0]);
	heightSprite =abs( gvertices[17] - gvertices[1]);

}
void Sprite::LoadBmp(const char* imagePath) {
	DataBmp d=importBmp.LoadTexture(imagePath, renderer);
	data.width = d.width;
	data.height = d.height;
	data.id = d.id;
	idTexture = d.id;
	cout << "idtexture bmp " << idTexture<<endl;
	cout << "width sprite " << data.width<<endl;
	SetFrameValues();
}
void Sprite::SetFrameValues(){
	widthFrame = 192;
	heightFrame = 192;
}
void Sprite::SetFrame(int id) {
	
	x = (int)(id % 3)*widthFrame;
	y = (int)(id / 3)*heightFrame;
	gvertices[6]=  x / data.width;//u 0
	gvertices[7] = 1.0f - y / data.height;//v 0
	
	gvertices[14] = (x + widthFrame) / data.width;// u 1
	gvertices[15] = 1.0f - y / data.height;//v 1
	
	gvertices[22] = x / data.width;//u 2
	gvertices[23] = 1.0f - (y + heightFrame) / data.height;//v2

	gvertices[30] = (x + widthFrame) / data.width;//u3
	gvertices[31] = 1.0f - (y + heightFrame )/ data.height;//v3
	
	int size = sizeof(float) * 32;
	vertexBuffer = renderer->SetBufferData(gvertices, size);

}
Sprite::Sprite(Renderer* renderer):Shape(renderer) {


}