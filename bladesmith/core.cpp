#include "core.h"

Core::Core()
{
   
}

std::vector<Camera*> Core::sortCameras() {
	std::vector<Camera*> sortedList = cameras;
	bool passSucces = false;
	bool hasSwapped = false;
	while (!passSucces) {
		hasSwapped = false;
		for (int i = 0; i <= sortedList.size() - 1; i++) {
			if(i == sortedList.size()-1){
				if (sortedList[i]->getPriority() > sortedList[i + 1]->getPriority()) {
					Camera* c = sortedList[i];
					Camera* cc = sortedList[i+1];
					sortedList[i] = cc;
					sortedList[i + 1] = c;
					hasSwapped = true;
				}
				if (!hasSwapped) {
					passSucces = true;
				}
			}
		}
	}
	return sortedList;
}

Core::~Core()
{
   
}
