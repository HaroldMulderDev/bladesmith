#ifndef INTERACTOR_H
#define INTERACTOR_H

#include "sprite.h"
#include <glm/gtc/matrix_transform.hpp>

class Interactor
{
public:

   // Interactor constructor allows for setting the Interactors parent if none is set parent will be a nullptr
   Interactor(Interactor* parent = nullptr);

   // Interactor update function can be overridden to allow for updating the Interactor
   virtual void update(){
   
   }

   void setSprite(Sprite* spr) {
	   sprite = spr;
   }

   Sprite* getSprite() {
	   return sprite;
   }

   Interactor* getParent() {
	   return parent;
   }

   glm::vec3 getPosition() {
	   return position;
   }

   void addPosition(glm::vec3 amount) {
	   position += amount;
   }

   glm::vec3 getScale() {
	   return scale;
   }

   glm::vec3 getRotation() {
	   return rotation;
   }

   // Interactor destructor
   ~Interactor();
private:

	Interactor* parent = nullptr;
	Sprite* sprite;
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;
};

#endif // !INTERACTOR_H
