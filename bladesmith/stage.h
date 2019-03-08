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
private:

	std::vector<Interactor*> updateList;
	std::vector<Interactor*> renderList;
	//std::vector<Camera*> cameras;

};

#endif // !STAGE_H
