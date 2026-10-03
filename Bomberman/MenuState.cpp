#include <cstring>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "MenuState.h"
#include "Game.h"


#define TITLE "POCKET BOMBERMAN"
#define TITLE_Y 20
#define OPTIONS_X 40
#define OPTIONS_Y 56
#define OPTIONS_STEP 16
#define CURSOR_X 28

static const char *OPTION_NAMES[] = { "JUGAR", "INSTRUCCIONES", "CREDITOS", "SALIR" };


MenuState::MenuState()
{
	selected = PLAY;
	if (!text.init(Game::instance().getTexProgram()))
		std::cout << "Could not load images/font.png" << std::endl;
}

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
	text.render(TITLE, glm::vec2((GAME_WIDTH - 8 * int(strlen(TITLE))) / 2, TITLE_Y));
	for (int i = 0; i < NUM_OPTIONS; i++)
		text.render(OPTION_NAMES[i], glm::vec2(OPTIONS_X, OPTIONS_Y + i * OPTIONS_STEP));
	text.render(">", glm::vec2(CURSOR_X, OPTIONS_Y + selected * OPTIONS_STEP));
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
