//enemy location
//enemy spawn
//enemy movement
//bullets
//collision?
class GameState {
public:
	GameState();
	std::vector<Enemy> enemies;
	std::vector<Bullet> bullets;
};
GameState theState;