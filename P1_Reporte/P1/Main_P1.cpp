#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificación de errores de creacion  ventana
	if (window== NULL) 
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

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	//VAO
	float vertices[] = {
		-0.9f, 0.2f,  0.0f,    1.0f,   0.98f, 0.0f,  // A
		-0.3f, 0.2f,  0.0f,    1.0f,   0.98f, 0.0f,  // B
		-0.6f, 0.8f,  0.0f,    1.0f,   0.98f, 0.0f,  // C
		0.1f,  0.2f,  0.0f,    0.02f,  1.0f,  0.0f, //  D
		0.4f,  0.7f,  0.0f,    0.02f,  1.0f,  0.0f,  // E
		0.6f,  0.7f,  0.0f,    0.02f,  1.0f,  0.0f,  // F
		0.9f,  0.2f,  0.0f,    0.02f,  1.0f,  0.0f,  // G
		-0.9f, -0.5f, 0.0f,    1.0f,   0.0f,  0.02f, //  H
		-0.8f, -0.9f, 0.0f,    1.0f,   0.0f,  0.02f,  // I
		-0.4f, -0.9f, 0.0f,    1.0f,   0.0f,  0.02f,  // J
		-0.3f, -0.5f, 0.0f,    1.0f,   0.0f,  0.02f,  // K
		-0.6f, -0.2f, 0.0f,    1.0f,   0.0f,  0.02f, //  L
		0.1f,  -0.4f, 0.0f,    0.0f,   0.5f,  1.0f,  // M
		0.1f,  -0.8f, 0.0f,    0.0f,   0.5f,  1.0f,  // N
		0.9f,  -0.8f, 0.0f,    0.0f,   0.5f,  1.0f,  // O
		0.9f,  -0.4f, 0.0f,    0.0f,   0.5f,  1.0f, //  P
	};

	//EBO
	unsigned int indices[] = {  // note that we start from 0!
		0,2,1,// second Triangle
		3,4,5,6,
		7,8,9,10,11,
		12,13,14,
		15,14,12
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Desenlazamos de memoria el VAO


	
	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aquí
		OurShader.Use();
		glBindVertexArray(VAO);
		glPointSize(10);
		//glDrawArrays(GL_LINES, 0, 4);
		//glDrawArrays(GL_LINE_LOOP, 0,4);
		//glDrawArrays(GL_TRIANGLES, 1,3);//trabaja con VAO
	    glDrawElements(GL_TRIANGLES,3, GL_UNSIGNED_INT, (GLvoid*)(0*sizeof(GLfloat))); //trabaja con VBO
		glDrawElements(GL_LINE_LOOP,4, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); //trabaja con VBO
		glDrawElements(GL_LINE_LOOP,5, GL_UNSIGNED_INT, (GLvoid*)(7 * sizeof(GLfloat))); //trabaja con VBO
		glDrawElements(GL_TRIANGLES,3, GL_UNSIGNED_INT, (GLvoid*)(12 * sizeof(GLfloat))); //trabaja con VBO
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(15 * sizeof(GLfloat))); //trabaja con VBO


		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}