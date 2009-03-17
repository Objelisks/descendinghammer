#include "bulletManager.h"
#include "gameState.h"

BulletManager::BulletManager()
{

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

void BulletManager::collideWithShips()
{

};