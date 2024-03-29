#ifndef _resources_inc
#define _resources_inc

#include "map"
#include "vector"
#include "allegro.h"

class Resources
{
public:
	Resources();
	void destroy();
	void destroyBmp(std::string bmp);
	std::map<std::string,BITMAP*> images;
	std::map<std::string,std::vector<BITMAP*>> effects;
};

#endif