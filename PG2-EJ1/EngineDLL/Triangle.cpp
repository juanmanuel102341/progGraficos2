#include"Triangle.h"
Triangle::Triangle(Renderer* renderer) :Shape(renderer) {


}
void Triangle::Start() {
	gvertices = new float[18]
	{
		-0.5f, -0.5f, 0.0f,
		1.0f,0.0f,0.0f,
		0.5f,-0.5f, 0.0f,
		1.0f,0.0f,0.0f,
		0.0f,0.5f, 0.0f,
		1.0f,0.0f,0.0f,
	};
	int size = 3 * sizeof(float) * 6;
	vertexBuffer=renderer->SetBufferData(gvertices,size);
	numberOfVertices = 3;
	primitive = strip;
	applyUv = false;
	tam = 6;
}



void Triangle::Stop() {
	material->Stop();
	renderer->DeleteVertexBuffer(vertexBuffer);
	delete[] gvertices;
}



