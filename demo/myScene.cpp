#include "myScene.h"
#include "myEntity.h"

myScene::myScene()
{
	myEntity* ent = new myEntity();
	addToRenderList(ent);
	addToUpdateList(ent);
}

myScene::~myScene()
{
   
}

void myScene::update() {
	for (int i = 0; i < getUpdateList().size(); i++) {
		getUpdateList()[i]->addPosition(glm::vec3(1, 1, 0));
	}
}
