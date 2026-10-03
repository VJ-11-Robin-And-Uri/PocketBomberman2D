#include <iostream>
#include <GLFW/glfw3.h>
#include "InstructionsState.h"
#include "Game.h"


void InstructionsState::enter()
{
	std::cout << "[state] INSTRUCTIONS" << std::endl; // TEMPORARY
}

void InstructionsState::update(int deltaTime)
{
	Game &game = Game::instance();

	if (game.getKeyDown(GLFW_KEY_ESCAPE) || game.getKeyDown(GLFW_KEY_ENTER))
		game.changeState(MENU);
}

void InstructionsState::render()
{
	//TODO: Render controls, objective and items
}
