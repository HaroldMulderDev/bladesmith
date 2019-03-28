#ifndef GRID_T_H
#define GRID_T_H

#include <vector>

template <class T>
class Grid
{
public:

   // grid constructor
	Grid(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;
		this->depth = 0;
   }

	Grid(unsigned int width, unsigned int height, unsigned int depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;
   }

   // grid destructor
	~Grid() {

   }

   // Get value at position in grid returns a nullptr if outside of grid bounds
   T* get(unsigned int x, unsigned int y) {
	   if (inGrid(x, y))
	   {
		  return grid[getGridIndex(x, y)];
	   }
	   else 
	   {
		   return nullptr;
	   }
   }

   // Get value at position in grid returns a nullptr if outside of grid bounds
   T* get(unsigned int x, unsigned int y, unsigned int z) {
	   if (inGrid(x, y, z))
	   {
		   return grid[getGridIndex(x, y, z)];
	   }
	   else
	   {
		   return nullptr;
	   }
   }

   // Set value at position in grid
   void set(unsigned int x, unsigned int y, T* value) {
	   if (inGrid(x, y))
	   {
		   grid[getGridIndex(x, y)] = value;
	   }
   }

   void set(unsigned int x, unsigned int y, unsigned int z, T* value) {
	   if (inGrid(x,y,z))
	   {
		   grid[getGridIndex(x,y,z)] = value;
	   }
   }
   
   // Fill the grid with a value type
   void fill() {
	   for (int x = 0; x < width; x++) {
		   for (int y = 0; y < height; y++) {
			   for (int z = 0; z < depth; z++) {
				   T* value = new T();
				   set(x, y, z, value);
			   }
		   }
	   }
   }

   // fill a box in the grid
   void fill(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
	   if (inGrid(x1, y1) && inGrid(x2, y2)) {
		   for (int x = x1; x < x2; x++) {
			   for (int y = y1; y < y2; y++) {
				   T value = new T();
				   set(x, y, value);
			   }
		   }
	   }
   }

   // fill a box in the grid
   void fill(unsigned int x1, unsigned int y1, unsigned int z1, unsigned int x2, unsigned int y2, unsigned int z2) {
	   if (inGrid(x1, y1, z1) && inGrid(x2, y2, z2)) {
		   for (int x = x1; x < x2; x++) {
			   for (int y = y1; y < y2; y++) {
				   for (int z = z1; z < z2; z++) {
					   T value = new T();
					   set(x, y, z, value);
				   }
			   }
		   }
	   }
   }
   
   // Check if given positions are within grid bounds
   bool inGrid(unsigned int x, unsigned int y, unsigned int z) {
	   if (x > width || y > height || z > depth) {
		   return false;
	   }
	   return true;
   }

   // Check if given positions are within grid bounds
   bool inGrid(unsigned int x, unsigned int y) {
	   if (x > width, y > height;) {
		   return false;
	   }
	   return true;
   }

   // Converts a dimensional set of values to a grid position
   unsigned int getGridIndex(unsigned int x, unsigned int y) {
	   return (y * width + x);
   }

   // Converts a dimensional set of values to a grid position
   unsigned int getGridIndex(unsigned int x, unsigned int y, unsigned int z) {
	   return ((z * (width * height)) + (y * width) + x);
   }

private:

	std::vector<T*> grid;
	unsigned int width; // The width of the grid
	unsigned int height; // The height of the grid
	unsigned int depth; // The depth of the grid. If zero we know this is a 2d grid

};

// Typedefs



#endif // !GRID_T_H
