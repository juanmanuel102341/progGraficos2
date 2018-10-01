#include"Shape.h"


Shape::Shape(Renderer* renderer) :Entity(renderer) {

}
void Shape::Draw(){
	renderer->LoadIdentity();
	renderer->SetModelMatriz(matrizModel);//le paso los vertices setiados de triangle
	material->Bind();//cargo el shader del material
	material->SetMatrixMaterial(renderer->GetMVP());//le paso la MVP al shader
	renderer->BeginDraw(0);
	renderer->BindBuffer(vertexBuffer, 0, 0);
	renderer->BeginDraw(1);
	renderer->BindBuffer(vertexBuffer, 1, (char*)(sizeof(float) * 3));
	renderer->DrawBuffer(numberOfVertices,primitive);
	
	renderer->EndDraw(0);
	renderer->EndDraw(1);

}