#include "myEntity.h"

myEntity::myEntity(){

	Sprite* pencils = new Sprite("assets/pencils.tga");
	this->setSprite(pencils);
}

myEntity::~myEntity()
{
   
}
