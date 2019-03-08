#ifndef INTERACTOR_H
#define INTERACTOR_H

class Interactor
{
public:

   // Interactor constructor allows for setting the Interactors parent if none is set parent will be a nullptr
   Interactor(Interactor* parent);

   // Interactor update function can be overridden to allow for updating the Interactor
   virtual void update(){
   
   }

   Interactor* getParent() {
	   return parent;
   }

   // Interactor destructor
   ~Interactor();
private:

	Interactor* parent = nullptr;
};

#endif // !INTERACTOR_H
