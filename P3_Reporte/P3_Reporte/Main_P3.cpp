#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 3", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {

		//Cubo Verde Fuerte
		-0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,//Front
		 0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,

		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,//Back
		 0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,

		 0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,

		-0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,

		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f, -0.5f, -0.5f, 0.65f, 0.84f, 0.12f,

		-0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		 0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f,  0.5f, 0.65f, 0.84f, 0.12f,
		-0.5f,  0.5f, -0.5f, 0.65f, 0.84f, 0.12f,

		//Cubo Verde Claro
		-0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,//Front
		 0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,//Back
		 0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,

		 0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,

		-0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.71f, 0.9f, 0.0f,

		-0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.71f, 0.9f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.71f, 0.9f, 0.0f,

		//Cubo Negro
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,//Front
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,//Back
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		//Cubo blanco
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,//Front
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,//Back
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
			
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
			 
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,

		//Cubo naranja
		-0.5f, -0.5f, 0.5f, 1.0f, 0.56f, 0.22f,//Front
		 0.5f, -0.5f, 0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.56f, 0.22f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,//Back
		 0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,

		 0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,

		-0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.56f, 0.22f,

		-0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.56f, 0.22f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.56f, 0.22f,

		//Cubo amarillo
		-0.5f, -0.5f, 0.5f, 1.0f, 0.94f, 0.25f,//Front
		 0.5f, -0.5f, 0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.94f, 0.25f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,//Back
		 0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,

		 0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,

		-0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.94f, 0.25f,

		-0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.94f, 0.25f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.94f, 0.25f,

		//Cubo rojo
		-0.5f, -0.5f, 0.5f, 1.0f, 0.18f, 0.19f,//Front
		 0.5f, -0.5f, 0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, 0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.18f, 0.19f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,//Back
		 0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,

		 0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,

		-0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,

		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.18f, 0.19f,

		-0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.18f, 0.19f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.18f, 0.19f,
			
	};


	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{

		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model = glm::mat4(1);
		glm::mat4 view = glm::mat4(1);


		view = glm::translate(view, glm::vec3(movX, movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));


		glBindVertexArray(VAO);

		////Cubo verde
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		//model= glm::mat4(1);

		////Cubo verde claro
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 36, 72);
		//model = glm::mat4(1);

		////Cubo negro
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 72, 108);
		//model = glm::mat4(1);

		////Cubo blanco
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 108, 144);
		//model = glm::mat4(1);

		////Cubo naranja
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 144, 180);
		//model = glm::mat4(1);

		////Cubo amarillo
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 180, 216);
		//model = glm::mat4(1);

		////Cubo rojo
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 216, 252);
		//model = glm::mat4(1);

		////Transformaciones
		//model = glm::scale(model, glm::vec3(0.0f, 0.0f, 0.0f));
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));


		//Cuerpo
		model = glm::scale(model, glm::vec3(1.376f, 0.875f, 0.75f));
		model = glm::translate(model, glm::vec3(-0.0455f, -0.0714f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 36, 72);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(1.5f, 1.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		//alas
		model = glm::scale(model, glm::vec3(0.875f, 0.5f, 0.25f));
		model = glm::translate(model, glm::vec3(-0.2143f, 0.25f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.5f, 0.25f));
		model = glm::translate(model, glm::vec3(1.5f, 0.25f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.875f, 0.5f, 0.25f));
		model = glm::translate(model, glm::vec3(-0.2143f, 0.25f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.5f, 0.25f));
		model = glm::translate(model, glm::vec3(1.5f, 0.25f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);
		model = glm::mat4(1);

		//Cola
		model = glm::scale(model, glm::vec3(0.375f, 0.375f, 0.5f));
		model = glm::translate(model, glm::vec3(2.5f, 0.83f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		//patas
		model = glm::scale(model, glm::vec3(0.25f, 0.375f, 0.25f));
		model = glm::translate(model, glm::vec3(0.5f, -1.83f, 1.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.375f));
		model = glm::translate(model, glm::vec3(0.5f, -4.0f, 0.83f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(-0.5f, -4.0f, 3.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(-0.5f, -4.0f, 1.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.375f, 0.25f));
		model = glm::translate(model, glm::vec3(0.5f, -1.83f, -1.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.375f));
		model = glm::translate(model, glm::vec3(0.5f, -4.0f, -0.83f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(-0.5f, -4.0f, -3.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(-0.5f, -4.0f, -1.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		//Cabeza
		model = glm::scale(model, glm::vec3(0.75f, 1.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 1.0f, 1.0f));
		model = glm::translate(model, glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(1.125f, 0.375f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.167f, 4.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		//pico
		model = glm::scale(model, glm::vec3(0.375f, 0.25f, 0.25f));
		model = glm::translate(model, glm::vec3(-2.5f, 4.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 180);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.25f, 0.25f));
		model = glm::translate(model, glm::vec3(-6.5f, 3.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 216, 252);
		model = glm::mat4(1);

		//ojo
		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 9.5f, 3.501f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 9.5f, -3.501f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);

		//ojo dinosaurio
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(0.0f, 7.0f, 4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.083f, 0.083f, 0.125f));
		model = glm::translate(model, glm::vec3(0.0f, 21.21f, 4.501f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(0.0f, 7.0f, -4.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 144);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.083f, 0.083f, 0.125f));
		model = glm::translate(model, glm::vec3(0.0f, 21.21f, -4.501f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);

		//hocico dinosaurio
		model = glm::scale(model, glm::vec3(0.25f, 0.375f, 0.5f));
		model = glm::translate(model, glm::vec3(-3.5f, 4.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-6.5f, 13.5f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);
		
		model = glm::scale(model, glm::vec3(0.25f, 0.375f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 4.5f, 3.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model= glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 14.5f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 12.5f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-6.5f, 13.5f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 108);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.375f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 4.5f, -3.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 14.5f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.25f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-3.5f, 12.5f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);

		//dientes dinosaurio
		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-6.5f, 11.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-6.5f, 11.5f, 2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-6.5f, 11.5f, -2.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		//crestas dinosaurio
		model = glm::scale(model, glm::vec3(0.375f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-1.5f, 15.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.375f, 0.125f, 0.125f));
		model = glm::translate(model, glm::vec3(-0.167f, 15.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(3.5f, 6.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(3.5f, 5.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		model = glm::scale(model, glm::vec3(0.125f, 0.25f, 0.125f));
		model = glm::translate(model, glm::vec3(3.5f, 3.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);
		model = glm::mat4(1);

		glBindVertexArray(0);
			

		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow* window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.1f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.1f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		 movY += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		 movY -= 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.1f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.1f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.5f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.5f;
 }


