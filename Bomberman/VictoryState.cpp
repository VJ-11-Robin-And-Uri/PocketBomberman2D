#include <iostream>
#include <GLFW/glfw3.h>
#include "VictoryState.h"
#include "Game.h"


void VictoryState::enter()
{
	std::cout << "[state] VICTORY" << std::endl; // TEMPORARY
}

void VictoryState::update(int deltaTime)
{
	if (Game::instance().getKeyDown(GLFW_KEY_ENTER))
		Game::instance().changeState(MENU);
}

void VictoryState::render()
{
	//TODO: Render the victory screen
}
