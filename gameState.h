#ifndef _gameState_inc
#define _gameState_inc

#include "allegro.h"
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "screen.h"
#include "world.h"
#include "enemyManager.h"
#include "bulletManager.h"
#include "effectManager.h"
#include "vector"
#include "resources.h"
#include "txtScreen.h"

class GameState {
public:
	static GameState* Instance();
	void Initialize();
	void Destroy();
	bool GAME_ENDED;
	EnemyManager enemyManager;
	BulletManager bulletManager;
	EffectManager effectManager;
	Screen* currentScreen;
	Player player;
	World world;
	Resources resources;
	int difficulty;
	bool ending;
	int score;
	int humans;
	int humansToKill;
	int menuChooser;
	void updateWorld();
	void addEnemy(Enemy e);
	void addBullet(Bullet b);
	void addEffect(Effect e);
	void addText(std::string str);
	void difficate();
	int collideEnemyWithBullets(Enemy e);
	TextScreen txtScreen;
protected:
	GameState();
	GameState(const GameState&);
	GameState& operator= (const GameState&);
private:
	static GameState* instance;
	bool collide(Coordinate pos1, Coordinate pos2, int size);
	int textTimer;
	bool scumMsg;
	bool earthMsg;
};

GameState* theState();

#endif