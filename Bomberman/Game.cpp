#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include "Game.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "PausedState.h"
#include "InstructionsState.h"
#include "CreditsState.h"
#include "GameOverState.h"
#include "VictoryState.h"


Game::Game()
{
	for (int i = 0; i < NUM_STATES; i++)
		states[i] = NULL;
	current = NULL;
	currentId = previousId = MENU;
	pendingState = NO_STATE;
}

Game::~Game()
{
	for (int i = 0; i < NUM_STATES; i++)
		delete states[i];
}

void Game::init()
{
	memset(keys, false, sizeof(keys));
	memset(keysJustPressed, false, sizeof(keysJustPressed));
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	PlayingState *playing = new PlayingState();
	states[MENU] = new MenuState();
	states[PLAYING] = playing;
	states[PAUSED] = new PausedState(playing);
	states[INSTRUCTIONS_SCREEN] = new InstructionsState();
	states[CREDITS_SCREEN] = new CreditsState();
	states[GAME_OVER] = new GameOverState();
	states[VICTORY] = new VictoryState();

	setState(MENU);
}

bool Game::update(int deltaTime)
{
	current->update(deltaTime);
	if (pendingState != NO_STATE)
	{
		setState(StateId(pendingState));
		pendingState = NO_STATE;
	}
	for (auto& key : keysJustPressed)
		key = false;

	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	current->render();
}

void Game::keyPressed(int key)
{
	if (key < 0 || key > GLFW_KEY_LAST) return;
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

void Game::changeState(StateId id)
{
	pendingState = id;
}

void Game::quit()
{
	bPlay = false;
}

StateId Game::getPreviousState() const
{
	return previousId;
}

void Game::setState(StateId id)
{
	if (current != NULL)
		current->exit();
	previousId = currentId;
	currentId = id;
	current = states[id];
	current->enter();
}
