#include "resources.h"
#include "allegro.h"
#include "iostream"
#include "fstream"
#include "string"
#include "common.h"
#include "vector"

Resources::Resources()
{
	images = std::map<std::string,BITMAP*>();
	effects = std::map<std::string, std::vector<BITMAP*>>();
	std::ifstream files;
	files.open("Images/index.txt",std::ifstream::in);
	while(!files.eof())
	{
		std::string name = "";
		std::getline(files,name,'\n');
		if(name.find("/") == 0)
		{
			int count = std::atoi(&name.c_str()[1]);
			name = name.substr(2);
			std::vector<BITMAP*> imgs;
			for(int i=0; i<count+1; i++)
			{
				imgs.insert(imgs.end(), load_bitmap(("Images/"+name+"/"+name+toString(i)+".bmp").c_str(),0));
			}
			effects.insert(effects.end(), std::pair<std::string,std::vector<BITMAP*>>(name,imgs));
		}
		else
		{
			images.insert(images.end(),std::pair<std::string,BITMAP*>(name,load_bitmap(("Images/"+name+".bmp").c_str(),0)));
		}
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