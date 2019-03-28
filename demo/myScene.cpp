#include "myScene.h"
#include "myEntity.h"

myScene::myScene()
{
	myEntity* ent = new myEntity();
	addToRenderList(ent);
}

myScene::~myScene()
{
   
}
