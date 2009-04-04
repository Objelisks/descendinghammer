#include "gamestate.h"
#include "player.h"
#include "bullet.h"
#include "list"
#include "mainScreen.h"
#include "menu.h"
#include "coordinate.h"
#include "screen.h"
#include "allegro.h"
#include "common.h"
#include "boost/random/linear_congruential.hpp"
#include "behaviors.h"

#include "txtScreen.h"

GameState* GameState::instance = 0;

GameState* GameState::Instance()
{
	if(instance == 0)
	{
		instance = new GameState;
	}
	return instance;
};

GameState::GameState()
{
	GAME_ENDED = false;
};

void GameState::Initialize()
{
	menuChooser = 0;
	difficulty = 5000;
	currentScreen = new Menu(&menuChooser);

	txtScreen = TextScreen(currentScreen->m_screen, 444, 392);
	world = World(200,800,200);
	score = 0;
	humans = INT_MAX; //initial attack wiped out most of them
	humansToKill = 0;
	textTimer = 0;
	earthMsg = false;
	scumMsg = false;
	ending = false;
};

void GameState::Destroy()
{
	delete currentScreen;
	resources.destroy();
};

void GameState::updateWorld()
{
	enemyManager.moveAll();

	bulletManager.moveAll();

	for(std::list<Effect>::iterator iter = effectManager.effects.begin(); iter!= effectManager.effects.end();)
	{
		if(iter->dead)
		{
			iter = effectManager.effects.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	player.update();

	if(humansToKill > 0 && humans > 0)
	{
		int kill = (rand()*32)%(humansToKill+1);
		humans-=kill;
		humansToKill-=kill;
	}
	if(humans <= 0)
	{
		humans = 0;
		ending = true;
	}

	int humanTest = humans;
	while(humanTest > 1000)
	{
		humanTest = humanTest / 10;
	}
	if(!earthMsg && humanTest%100 == 0)
	{
		txtScreen.addText(toString(humans)+" humans left.");
		earthMsg = true;
	}
	if(humanTest%10 == 1)
	{
		earthMsg = false;
	}
	if(!scumMsg && score%20 == 0 && score != 0)
	{
		txtScreen.addText(toString(score)+" alien scum kills");
		scumMsg = true;
	}
	if(score%20 == 1)
	{
		scumMsg = false;
	}

	textTimer++;
	if(textTimer > 80)
	{
		txtScreen.addText("");
		textTimer = 0;
	}
};

void GameState::difficate()
{
switch(difficulty)
{
	case 5000:
		addEnemy(Enemy(&Behaviors::Straight));
		break;
	case 48000:
		addEnemy(Enemy(&Behaviors::Zag));
		break;
	case 1000000000:
		addEnemy(Enemy(&Behaviors::Wave));
		break;
}
};

void GameState::addEnemy(Enemy e)
{
	theState()->enemyManager.addEnemy(e);
};

void GameState::addBullet(Bullet b)
{
	theState()->bulletManager.addBullet(b);
};

void GameState::addEffect(Effect e)
{
	theState()->effectManager.addEffect(e);
};

void GameState::addText(std::string str)
{
	theState()->txtScreen.addText(str);
};

int GameState::collideEnemyWithBullets(Enemy e)
{
	int dmg = 0;
	for(std::list<Bullet>::iterator iter = theState()->bulletManager.bullets.begin(); iter!= theState()->bulletManager.bullets.end();)
	{
		if(collide(iter->pos,e.pos,e.size))
		{
			dmg = dmg + iter->damage;
			iter = theState()->bulletManager.bullets.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return dmg;
};

bool GameState::collide(Coordinate pos1, Coordinate pos2, int size)
{
	if(pos1.x < pos2.x+size && pos1.x > pos2.x-size)
	{
	if(pos1.y < pos2.y+size && pos1.y > pos2.y-size)
	{
	if(pos1.z < pos2.z+size && pos1.z > pos2.z-size)
	{
		return true;
	}}}
	return false;
};

GameState* theState()
{
	return GameState::Instance();
};