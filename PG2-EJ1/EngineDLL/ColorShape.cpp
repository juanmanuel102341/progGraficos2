#include"ColorShape.h"

ColorShape::ColorShape(Renderer* renderer) :Shape(renderer) {

}
void ColorShape::Start() {
	gvertices=new float[24]
	{	-0.5f, -0.5f, 0.0f,
		1.0f,0.0f,0.0f,//color
		0.5f, -0.5f, 0.0f,
		0.0f,1.0f,0.0f,//color
		-0.5f, 0.5f, 0.0f,
		0.0f,0.0f,1.0f,//color
		0.5f,  0.5f, 0.0f,
		1.0f,0.0f,0.0f,//color
		
	};
	
	int size = 3 * sizeof(float) * 8;
	vertexBuffer = renderer->SetBufferData(gvertices, size);
	numberOfVertices = 4;
	primitive = strip;
	applyUv = false;
	applyColor = true;
	tam = 6;
//	bufferColor = renderer->SetBufferData(colorsVertices, size);
}

void ColorShape::Stop() {
	material->Stop();
	renderer->DeleteVertexBuffer(vertexBuffer);
	delete[] gvertices;
}