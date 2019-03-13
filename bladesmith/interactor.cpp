#include "interactor.h"

Interactor::Interactor(Interactor* parent)
{
	this->parent = parent;
	this->position = glm::vec3(0, 0, 0);
	this->scale = glm::vec3(1, 1, 1);
	this->rotation = glm::vec3(0, 0, 0);
}


Interactor::~Interactor()
{
   
}
