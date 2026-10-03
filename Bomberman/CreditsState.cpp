#include <iostream>
#include <GLFW/glfw3.h>
#include "CreditsState.h"
#include "Game.h"


void CreditsState::enter()
{
	std::cout << "[state] CREDITS" << std::endl; // TEMPORARY
}

void CreditsState::update(int deltaTime)
{
	Game &game = Game::instance();

	if (game.getKeyDown(GLFW_KEY_ESCAPE) || game.getKeyDown(GLFW_KEY_ENTER))
		game.changeState(MENU);
}

void CreditsState::render()
{
	//TODO: Render the credits (roles and names)
}
