#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE


#include <GLFW/glfw3.h>
#include "GameState.h"


#define GAME_WIDTH 160
#define GAME_HEIGHT 120
#define SCALE 4
#define SCREEN_WIDTH (GAME_WIDTH * SCALE)
#define SCREEN_HEIGHT (GAME_HEIGHT * SCALE)


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

private:
	Game();
	~Game();

public:
	static Game &instance()
	{
		static Game G;

		return G;
	}

	void init();
	bool update(int deltaTime);
	void render();

	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);

	bool getKey(int key) const;
	bool getKeyDown(int key) const;

	// The change is applied at the end of the current update, never in the middle of it
	void changeState(StateId id);
	void quit();

private:
	void setState(StateId id);

private:
	enum { NO_STATE = -1 };

	bool bPlay; // Continue to play game?
	bool keys[GLFW_KEY_LAST+1]; // Store key states so that
							    // we can have access at any time
	bool keysJustPressed[GLFW_KEY_LAST + 1];

	GameState *states[NUM_STATES]; // Owned by Game
	GameState *current;
	int pendingState;

};


#endif // _GAME_INCLUDE

