#include"ColorShape.h"

ColorShape::ColorShape(Renderer* renderer) :Entity(renderer) {

}
void ColorShape::Start() {
	gvertices=new float[24]
	{	-0.5f, -0.5f, 0.0f,
		1.0f,0.0f,0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,1.0f,0.0f,
		-0.5f,  0.5f, 0.0f,
		0.0f,0.0f,1.0f,
		0.5f,  0.5f, 0.0f,
		1.0f,0.0f,0.0f,
	};
	
	int size = 3 * sizeof(float) * 8;
	vertexBuffer = renderer->SetBufferData(gvertices, size);
//	bufferColor = renderer->SetBufferData(colorsVertices, size);
}
void ColorShape::Draw() {
	renderer->LoadIdentity();
	renderer->SetModelMatriz(matrizModel);//le paso los vertices setiados de triangle
	material->Bind();//cargo el shader del material
	material->SetMatrixMaterial(renderer->GetMVP());//le paso la MVP al shader
	renderer->BeginDraw(0);
	renderer->BindBuffer(vertexBuffer,0,0);
	renderer->BeginDraw(1);
	renderer->BindBuffer(vertexBuffer, 1,(char*)(sizeof(float)*3));
	renderer->DrawBuffer(4);
	renderer->EndDraw(0);
	

	//renderer->DrawBuffer(4);
	renderer->EndDraw(1);
}
void ColorShape::Stop() {

}