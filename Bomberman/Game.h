#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE


#include <GLFW/glfw3.h>
#include "Scene.h"


#define GAME_WIDTH 160
#define GAME_HEIGHT 120
#define SCALE 4
#define SCREEN_WIDTH (GAME_WIDTH * SCALE)
#define SCREEN_HEIGHT (GAME_HEIGHT * SCALE)


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

private:
	Game() {}
	
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

private:
	bool bPlay; // Continue to play game?
	bool keys[GLFW_KEY_LAST+1]; // Store key states so that 
							    // we can have access at any time
	Scene scene;

	bool keysJustPressed[GLFW_KEY_LAST + 1];

};


#endif // _GAME_INCLUDE


