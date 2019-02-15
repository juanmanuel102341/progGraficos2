#include"Sprite.h"

void Sprite::Stop(){
}
void Sprite::SetMyVertices(float* vertices) {
	gvertices = new float[30];
	gvertices =vertices;
}
void Sprite::PassingVerticesTileMap(float* vertices) {
	gvertices = vertices;
	int size = sizeof(float) * 30;
	vertexBuffer = renderer->SetBufferData(gvertices, size);
}
void Sprite::Start() {
	
	/*{	
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
	*/
	int size = sizeof(float) * 30;
	vertexBuffer = renderer->SetBufferData(gvertices, size);
	numberOfVertices = 6;
	primitive = triangle;
	applyUv = true;
	applyColor = false;
	tam = 5;
	
	widthSprite = gvertices[5]-gvertices[0];
	heightSprite = gvertices[11]-gvertices[1];
	heightSprite = heightSprite*-1;
	cout << "widht sprite " << widthSprite << endl;
	cout << "height sprite " << heightSprite << endl;
	SetPos(POS_MAP_X, POS_MAP_Y, 0);
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
	int index = 0;
	x = (int)(id % 3)*widthFrame;
	y = (int)(id / 3)*heightFrame;
	
	index += 3;
	//vertice, esquina superior izquierda

	gvertices[index] = x / data.width;//vertice sup izquierdo, siempre 0 1
	index++;
	gvertices[index] = 1.0f - y / data.height;//
	index++;
	index += 3;
	//vertice esquina sup derecha
	gvertices[index] = (x + widthFrame) / data.width;// vertice sup derecho
	index++;
	gvertices[index] = 1.0f - y / data.height;//
	index++;
	index += 3;
	//vert inf izquierdo
	gvertices[index] = x / data.width;// vertice inferior izquierdo
	index++;
	gvertices[index] = 1.0f - (y + heightFrame) / data.height;//
	index++;
	index += 3;
	//****2do poligono*****
	//vertice esquina sup derecha
	gvertices[index] = (x + widthFrame) / data.width;// vertice sup derecho
	index++;
	gvertices[index] = 1.0f - y / data.height;//
	index++;
	index += 3;
	//vert inf izquierdo
	gvertices[index] = x / data.width;// vertice inferior izquierdo
	index++;
	gvertices[index] = 1.0f - (y + heightFrame) / data.height;//
	index++;
	index += 3;
	// vertice esquina inferior derecha
	gvertices[index] = (x + widthFrame) / data.width;//vertice inferior derrecho
	index++;
	gvertices[index] = 1.0f - (y + heightFrame) / data.height;//
	index++;
	int size = sizeof(float) * 30;
	vertexBuffer = renderer->SetBufferData(gvertices, size);

}
Sprite::Sprite(Renderer* renderer):Shape(renderer) {


}