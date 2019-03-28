#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "scene.h"

class Camera {
public:
	Camera(glm::vec3 pos, glm::vec2 size, Scene* scene, int priority);
	~Camera();
	void computeMatricesFromInputs(GLFWwindow* window);
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();
	glm::vec3 getCursor();
	int getPriority() {
		return priority;
	}

	Scene* getScene(){
		return scene;
	}

private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;

	// Initial position : on +Z
	glm::vec3 position;
	glm::vec3 cursor;
	float speed;
	int priority;
	Scene* scene;
};

#endif // !CAMERA_H
