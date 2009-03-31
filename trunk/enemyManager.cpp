#include "enemyManager.h"
#include "list"
#include "gameState.h"

EnemyManager::EnemyManager()
{
	enemies = std::list<Enemy>();
};

void EnemyManager::spawnEnemy(Enemy e)
{
	enemies.insert(enemies.begin(),e);
};

void EnemyManager::moveAll()
{
	for(std::list<Enemy>::iterator iter = enemies.begin(); iter!= enemies.end();)
	{
		if(iter->dead)
		{
			iter = enemies.erase(iter);
		}
		else
		{
			iter->update();
			iter++;
		}
	}
};