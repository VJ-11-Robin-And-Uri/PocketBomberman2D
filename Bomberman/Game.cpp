#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"
#include "Shader.h"
#include "ShaderProgram.h"
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
	texProgram = NULL;
}

Game::~Game()
{
	for (int i = 0; i < NUM_STATES; i++)
		delete states[i];
	if (texProgram != NULL)
	{
		texProgram->free();
		delete texProgram;
	}
}

void Game::init()
{
	memset(keys, false, sizeof(keys));
	memset(keysJustPressed, false, sizeof(keysJustPressed));
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	initShaders();
	projection = glm::ortho(0.f, float(GAME_WIDTH), float(GAME_HEIGHT), 0.f);

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
	texProgram->use();
	texProgram->setUniformMatrix4f("projection", projection);
	texProgram->setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	texProgram->setUniformMatrix4f("modelview", glm::mat4(1.0f));
	texProgram->setUniform2f("texCoordDispl", 0.f, 0.f);
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

ShaderProgram &Game::getTexProgram()
{
	return *texProgram;
}

void Game::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if (!vShader.isCompiled())
	{
		std::cout << "Vertex Shader Error" << std::endl;
		std::cout << "" << vShader.log() << std::endl << std::endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if (!fShader.isCompiled())
	{
		std::cout << "Fragment Shader Error" << std::endl;
		std::cout << "" << fShader.log() << std::endl << std::endl;
	}
	texProgram = new ShaderProgram();
	texProgram->init();
	texProgram->addShader(vShader);
	texProgram->addShader(fShader);
	texProgram->link();
	if (!texProgram->isLinked())
	{
		std::cout << "Shader Linking Error" << std::endl;
		std::cout << "" << texProgram->log() << std::endl << std::endl;
	}
	texProgram->bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
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
