#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "PausedState.h"
#include "PlayingState.h"
#include "Game.h"


PausedState::PausedState(PlayingState *playing)
{
	this->playing = playing;
	selected = RESUME;
}

void PausedState::enter()
{
	std::cout << "[state] PAUSED" << std::endl; // TEMPORARY
	selected = RESUME;
}

void PausedState::update(int deltaTime)
{
	Game &game = Game::instance();

	if (game.getKeyDown(GLFW_KEY_ESCAPE))
		game.changeState(PLAYING);
	if (game.getKeyDown(GLFW_KEY_UP))
		selected = (selected + NUM_OPTIONS - 1) % NUM_OPTIONS;
	if (game.getKeyDown(GLFW_KEY_DOWN))
		selected = (selected + 1) % NUM_OPTIONS;
	if (game.getKeyDown(GLFW_KEY_ENTER))
		confirm();
}

void PausedState::render()
{
	playing->render();
	//TODO: Render pause options and highlight the selected one
}

void PausedState::confirm()
{
	switch (selected)
	{
	case RESUME:
		Game::instance().changeState(PLAYING);
		break;
	case BACK_TO_MENU:
		Game::instance().changeState(MENU);
		break;
	}
}
