#include"Shape.h"


Shape::Shape(Renderer* renderer) :Entity(renderer) {

}
void Shape::Draw(){
	renderer->LoadIdentity();
	renderer->SetModelMatriz(matrizModel);//le paso los vertices setiados de triangle
	material->Bind();//cargo el shader del material

	material->SetMatrixMaterial(renderer->GetMVP());//le paso la MVP al shader
	if (applyUv) {
		material->SetSpriteMaterial(idTexture);
	}
	renderer->BeginDraw(0);
	renderer->BindBuffer(vertexBuffer, 0,3,tam, 0);
	if (applyColor) {
		renderer->BeginDraw(1);
		renderer->BindBuffer(vertexBuffer, 1, 3, tam, (char*)(sizeof(float) * 3));
	}
	if (applyUv) {
		renderer->BeginDraw(2);
		renderer->BindBuffer(vertexBuffer, 2, 2, tam, (char*)(sizeof(float) * 3));
		
	}
	//renderer->BindTexture(idTexture);
	renderer->DrawBuffer(numberOfVertices,primitive);
	renderer->EndDraw(0);
	renderer->EndDraw(1);
	if (applyUv) {
		renderer->EndDraw(2);
	}
}