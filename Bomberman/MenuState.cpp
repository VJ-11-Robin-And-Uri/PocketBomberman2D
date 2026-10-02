#include <GLFW/glfw3.h>
#include "MenuState.h"
#include "Game.h"


void MenuState::enter()
{
	selected = PLAY;
}

void MenuState::exit()
{
}

void MenuState::update(int deltaTime)
{
	Game &game = Game::instance();

	if (game.getKeyDown(GLFW_KEY_UP))
		selected = (selected + NUM_OPTIONS - 1) % NUM_OPTIONS;
	if (game.getKeyDown(GLFW_KEY_DOWN))
		selected = (selected + 1) % NUM_OPTIONS;
	if (game.getKeyDown(GLFW_KEY_ENTER))
		confirm();
}

void MenuState::render()
{
	//TODO: Render menu options and highlight the selected one
}

void MenuState::confirm()
{
	Game &game = Game::instance();

	switch (selected)
	{
	case PLAY:
		game.changeState(PLAYING);
		break;
	case INSTRUCTIONS:
		game.changeState(INSTRUCTIONS_SCREEN);
		break;
	case CREDITS:
		game.changeState(CREDITS_SCREEN);
		break;
	case QUIT:
		game.quit();
		break;
	}
}
