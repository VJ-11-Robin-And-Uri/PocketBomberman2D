#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init(ShaderProgram &program); // Call once; the program is shared and owned by Game
	void loadLevel(int level); // (Re)creates map and player; can be called many times
	void update(int deltaTime);
	void render();

private:
	TileMap *map;
	Player *player;
	ShaderProgram *texProgram;
	float currentTime;

};


#endif // _SCENE_INCLUDE

