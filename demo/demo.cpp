// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <bladesmith/renderer.h>
#include <bladesmith/camera.h>
#include <bladesmith/sprite.h>
#include <bladesmith/grid_T.h>
#include "myScene.h"

int main( void )
{

	Renderer renderer(1280, 720);
	myScene* scene = new myScene();
	Camera* cam = new Camera(glm::vec3(0, 0, 5), glm::vec2(1280, 720), scene, 0);

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderer.renderCamera(cam);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
