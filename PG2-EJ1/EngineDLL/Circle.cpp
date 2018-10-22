#include"Circle.h"

Circle::Circle(Renderer* renderer) :Shape(renderer) {

}
void Circle::Start() {
	
	numberOfVerticesCircle = 20;
 totalAngle = 360.0f / numberOfVerticesCircle;
 radius = 0.7f;
 angle = 0.0f;
 gvertices = new float[numberOfVerticesCircle*6];
 gvertices[0] = 0.0f;
 gvertices[1] = 0.0f;
 gvertices[2] = 0.0f;
 gvertices[3] = 1.0f;
 gvertices[4] = 0.0f;
 gvertices[5] = 0.0f;

	for (int i = 6; i < numberOfVerticesCircle*6; i+=6) {
		gvertices[i] = cos(angle)*radius;
		gvertices[i + 1] = sin(angle)*radius;
		gvertices[i + 2] = 0.0f;
		gvertices[i + 3] = 1.0f;
		gvertices[i + 4] = 0.0f;
		gvertices[i + 5] = 0.0f;
		angle +=totalAngle*3.1415f;
	}

	int size = sizeof(float)*numberOfVerticesCircle*6;
	vertexBuffer = renderer->SetBufferData(gvertices,size);
	numberOfVertices = numberOfVerticesCircle;
	primitive = fun;
	applyUv = false;
	tam = 6;
}
void Circle::Stop() {
	material->Stop();
	renderer->DeleteVertexBuffer(vertexBuffer);
	delete[] gvertices;
}