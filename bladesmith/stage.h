#ifndef STAGE_H
#define STAGE_H

#include "interactor.h"
//#include "camera.h"
#include <vector>

class Stage
{
public:

   // Stage constructor
   Stage();

   // Stage destructor
   ~Stage();
   
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

#endif // !STAGE_H
