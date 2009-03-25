#include "bulletManager.h"
#include "gameState.h"
#include "list"

BulletManager::BulletManager()
{
	bullets = std::list<Bullet>();
};

void BulletManager::spawnBullet(Bullet b)
{
	bullets.insert(bullets.begin(),b);
};

void BulletManager::moveAll()
{
	for(std::list<Bullet>::iterator iter = bullets.begin(); iter!= bullets.end();)
	{
		if(iter->dead)
		{
			iter = bullets.erase(iter);
		}
		else
		{
			iter->update();
			iter++;
		}
	}
};