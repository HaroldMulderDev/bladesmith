#ifndef CORE_H
#define CORE_H

#include "camera.h"

class Core
{
public:

   // Core constructor
   Core();

   // Core destructor
   ~Core();

   void addCamera(Camera* cam) {
	   cameras.push_back(cam);
   };
private:

	std::vector<Camera*> sortCameras();

	std::vector<Camera*> cameras;
};

#endif // !CORE_H
