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
	renderer->SetModelMatriz(matrizModel);//le paso los vertices setiados de triangle
	material->Bind();//cargo el shader del material
	material->SetMatrixMaterial(renderer->GetMVP());//le paso la MVP al shader
	renderer->Draw(vertexBuffer, 3);
}
void Triangle::Stop() {
	material->Stop();
	renderer->DeleteVertexBuffer(vertexBuffer);
	delete[] gvertices;
}



