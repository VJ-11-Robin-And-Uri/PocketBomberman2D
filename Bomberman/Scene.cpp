#include <iostream>
#include <cmath>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Game.h"


#define SCREEN_X 0
#define SCREEN_Y 0

#define INIT_PLAYER_X_TILES 7
#define INIT_PLAYER_Y_TILES 6


Scene::Scene()
{
	map = NULL;
	player = NULL;
	texProgram = NULL;
	currentTime = 0.0f;
}

Scene::~Scene()
{
	if(map != NULL)
		delete map;
	if(player != NULL)
		delete player;
}


void Scene::init(ShaderProgram &program)
{
	texProgram = &program;
}

void Scene::loadLevel(int level)
{
	if(map != NULL)
		delete map;
	if(player != NULL)
		delete player;
	map = TileMap::createTileMap("levels/level0" + std::to_string(level) + ".txt", glm::vec2(SCREEN_X, SCREEN_Y), *texProgram);
	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), *texProgram);
	player->setPosition(glm::vec2(INIT_PLAYER_X_TILES * map->getTileSize(), INIT_PLAYER_Y_TILES * map->getTileSize()));
	player->setTileMap(map);
	currentTime = 0.0f;
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
	player->update(deltaTime);
}

void Scene::render()
{
	glm::mat4 modelview;

	// Game::render already set the projection and color; other drawing may have changed these
	texProgram->use();
	modelview = glm::mat4(1.0f);
	texProgram->setUniformMatrix4f("modelview", modelview);
	texProgram->setUniform2f("texCoordDispl", 0.f, 0.f);
	map->render();
	player->render();
}



