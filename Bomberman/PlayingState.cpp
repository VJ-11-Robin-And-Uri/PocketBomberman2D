#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "PlayingState.h"
#include "Game.h"


PlayingState::PlayingState()
{
	scene.init();
}

void PlayingState::enter()
{
	std::cout << "[state] PLAYING" << std::endl; // TEMPORARY: no screens to see yet
	// Coming back from the pause menu must not restart the game
	if (Game::instance().getPreviousState() != PAUSED)
		scene.loadLevel(1);
}

void PlayingState::update(int deltaTime)
{
	if (Game::instance().getKeyDown(GLFW_KEY_ESCAPE))
	{
		Game::instance().changeState(PAUSED);
		return;
	}
	scene.update(deltaTime);
}

void PlayingState::render()
{
	scene.render();
}
