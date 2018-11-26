#include "Renderer.h"
#include"GL\glew.h"
#include"GLFW\glfw3.h"


Renderer::Renderer(Window* _window){
	std::cout << "Renderer: Csreado" << std::endl;;
	window = _window;
}


Renderer::~Renderer() {
	std::cout << "Renderer: Eliminado" << std::endl;
}
void Renderer::UpdateMVP(){
	MVP = matrizProyection*matrizView* matrizModel;
}
void Renderer::LoadIdentity() {
	matrizModel = glm::mat4(1.0f);
	UpdateMVP();
}
void Renderer::SetModelMatriz(glm::mat4 _model) {
	matrizModel = _model;
	UpdateMVP();
}
bool Renderer::Start() {
	std::cout << "Renderer: Start" << std::endl;
	glfwMakeContextCurrent((GLFWwindow*)window->GetWindow());
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return false;
	}

	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);
	matrizProyection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	matrizView = glm::lookAt(
		glm::vec3(0, 0,3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1,0)

		);
	matrizModel = glm::mat4(1.0f);
	UpdateMVP();
	return true;
}
glm::mat4& Renderer::GetMVP() {
	return MVP;
}
bool Renderer::Stop() {
	std::cout << "Renderer: Stop" << std::endl;
	glDeleteVertexArrays(1, &vertexArrayId);
	
	return true;
}
void Renderer::DeleteShader(unsigned int id) {

	glDeleteProgram(id);
}
void Renderer::DeleteVertexBuffer(unsigned int buffer){
	glDeleteBuffers(1, &buffer);
}
void Renderer::ClearColor() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}
void Renderer::ClearScreen(){
	
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::SwappBuffer(){
	glfwSwapBuffers((GLFWwindow*)window->GetWindow());
}

unsigned int Renderer::SetBufferData(float vertices[],int size) {
	
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	return buffer;
}
 unsigned int Renderer::GenTexture(int width, int height, unsigned char* data){
	 unsigned int textureId;
	 glGenTextures(1, &textureId);
	 glBindTexture(GL_TEXTURE_2D, textureId);
	 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	 //cout << "id textire renderer "<<textureId<<endl;
	 return textureId;
 
 }
void Renderer::BindTexture(unsigned int idTexture) {
	glBindTexture(GL_TEXTURE_2D, idTexture);
 }
void Renderer::BeginDraw(int id) {
	glEnableVertexAttribArray(id);
}
void Renderer::BindBuffer(unsigned int buffer,int id,int numberElements,int stride,char* offset) {
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(id, numberElements, GL_FLOAT, GL_FALSE, sizeof(float)*stride, offset);
}

void Renderer::DrawBuffer(int tam,Primitive prim) {
	switch (prim)
	{
	case strip:
		glDrawArrays(GL_TRIANGLE_STRIP, 0, tam);
		break;
	case fun:
		glDrawArrays(GL_TRIANGLE_FAN, 0, tam);
		break;
	default:
		break;
	}

}
void Renderer::EndDraw(int id) {
	glDisableVertexAttribArray(id);
}

unsigned int Renderer::LoadShader(const char * vertex_file_path, const char * fragment_file_path) {
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;


	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}



	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}



	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}


	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
void Renderer::Bind(unsigned int idProgram){

	glUseProgram(idProgram);
}
