#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "PlayingState.h"
#include "Game.h"


PlayingState::PlayingState()
{
	sceneInitialized = false;
}

void PlayingState::enter()
{
	std::cout << "[state] PLAYING" << std::endl; // TEMPORARY: no screens to see yet
	// TODO (step 3): replace with scene.loadLevel(1) on a new game; resuming from PAUSED must not reload
	if (!sceneInitialized)
	{
		scene.init();
		sceneInitialized = true;
	}
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
