#include"Triangle.h"
Triangle::Triangle(Renderer* renderer) :Entity(renderer) {


}
void Triangle::Start() {
	gvertices = new float[9]
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f,
	};
	int size = 3 * sizeof(float) * 3;
	vertexBuffer=renderer->SetBufferData(gvertices,size);
}


void Triangle::Draw() {
	renderer->LoadIdentity();
	renderer->SetModelMatriz(matrizModel);
	material->Bind();
	material->SetMatrixMaterial(renderer->GetMVP());
	renderer->Draw(vertexBuffer, 3);
}
void Triangle::Stop() {
	material->Stop();
	renderer->DeleteVertexBuffer(vertexBuffer);
	delete[] gvertices;
}



