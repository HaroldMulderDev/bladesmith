#ifndef SCENE_H
#define SCENE_H

#include "interactor.h"
//#include "camera.h"
#include <vector>

class Scene
{
public:

   // Stage constructor
   Scene();

   // Stage destructor
   ~Scene();
   
   std::vector<Interactor*> getRenderList() {
	   return renderList;
   }

   void addToRenderList(Interactor* i) {
	   renderList.push_back(i);
   }

   std::vector<Interactor*> getUpdateList() {
	   return updateList;
   }

   void addToUpdateList(Interactor* i) {
	   updateList.push_back(i);
   }
private:

	std::vector<Interactor*> updateList;
	std::vector<Interactor*> renderList;
	//std::vector<Camera*> cameras;

};

#endif // !SCENE_H
