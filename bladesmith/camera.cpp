#include <bladesmith/camera.h>

Camera::Camera(glm::vec3 pos, glm::vec2 size, Stage* stage) {
	this->stage = stage;
	glm::mat4 _viewMatrix;
	position = pos; //glm::vec3(0, 0, 5);
	cursor = glm::vec3(0, 0, 0);
	speed = 300.0f; // 300 units / second'
	//parameters glm::ortho(left, right, bottom, top, znear, zfar)
	_projectionMatrix = glm::ortho(pos.x, pos.x + size.x, pos.y + size.y, pos.y, 0.1f, 100.0f);
}

Camera::~Camera() {

}

glm::mat4 Camera::getProjectionMatrix() {
	return _projectionMatrix;
}

glm::mat4 Camera::getViewMatrix(){
	return _viewMatrix;
}

glm::vec3 Camera::getCursor(){
	return cursor;
}

void Camera::computeMatricesFromInputs(GLFWwindow* window)
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );

	// Right and Down vector
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);

	// Move up
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += up * deltaTime * speed;
	}
	// Move down
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= up * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	// View matrix
	_viewMatrix = glm::lookAt(
			position, // Camera is at (xpos,ypos,5), in World Space
			position + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
