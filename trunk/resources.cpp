#include "resources.h"
#include "allegro.h"
#include "iostream"
#include "fstream"
#include "string"
#include "common.h"

Resources::Resources()
{
	images = std::map<std::string,BITMAP*>();
	std::ifstream files;
	files.open("Images/index.txt",std::ifstream::in);
	while(!files.eof())
	{
		std::string name = "";
		std::getline(files,name,'\n');
		images.insert(images.end(),std::pair<std::string,BITMAP*>(name,load_bitmap(("Images/"+name).c_str(),0)));
	}
	files.close();
};

void Resources::destroy()
{
	for(std::map<std::string,BITMAP*>::iterator iter = images.begin(); iter!=images.end();iter++)
	{
		destroy_bitmap(iter->second);
	}
};

void Resources::destroyBmp(std::string bmp)
{
	destroy_bitmap(images[bmp]);
	images.erase(bmp);
};