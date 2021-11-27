#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

int main() {

	if (!glfwInit()) // Initialization GLFW
	{
		cout << "Error";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(640, 480, "First OpenGl", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Making the OpenGL context current
	GLenum err = glewInit(); // Initialization GLEW
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float vertices[] = {
	-0.5f, -0.5f,
	 0.5f, -0.5f,
	 0.0f,  0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	while (!glfwWindowShouldClose(window))
	{
		// Keep running
		glfwSwapBuffers(window);
		glfwPollEvents();

		// Render Background Color
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// DRAW TRIANGLES
		glDrawArrays(GL_TRIANGLES, 0, 3);

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}