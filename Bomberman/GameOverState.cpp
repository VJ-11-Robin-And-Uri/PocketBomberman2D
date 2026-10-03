#include <iostream>
#include <GLFW/glfw3.h>
#include "GameOverState.h"
#include "Game.h"


void GameOverState::enter()
{
	std::cout << "[state] GAME_OVER" << std::endl; // TEMPORARY
}

void GameOverState::update(int deltaTime)
{
	if (Game::instance().getKeyDown(GLFW_KEY_ENTER))
		Game::instance().changeState(MENU);
}

void GameOverState::render()
{
	//TODO: Render the game over screen
}
