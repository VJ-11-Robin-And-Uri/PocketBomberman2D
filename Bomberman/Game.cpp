#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include "Game.h"


void Game::init()
{
	memset(keys, false, sizeof(keys));
	memset(keysJustPressed, false, sizeof(keysJustPressed));
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	scene.init();
}

bool Game::update(int deltaTime)
{
	scene.update(deltaTime);
	for (auto& key : keysJustPressed)
		key = false;

	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene.render();
}

void Game::keyPressed(int key)
{
	if (key < 0 || key > GLFW_KEY_LAST) return;
	if(key == GLFW_KEY_ESCAPE) // Escape code
		bPlay = false;
	keys[key] = true;
	keysJustPressed[key] = true;
}

void Game::keyReleased(int key)
{
	if (key < 0 || key > GLFW_KEY_LAST) return;
	keys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	if (key < 0 || key > GLFW_KEY_LAST) return false;
	return keys[key];
}

bool Game::getKeyDown(int key) const
{
	if (key < 0 || key > GLFW_KEY_LAST) return false;
	return keysJustPressed[key];
}

