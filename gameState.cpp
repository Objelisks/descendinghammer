#include "coordinate.h"
#include "enemy.h"
#include "bullet.h"
#include "vector"

class GameState
{
public:
	GameState(){
		enemies = std::vector<Enemy>();
		bullets = std::vector<Bullet>();
	};
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;

} theState;