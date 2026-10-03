#pragma once

// Identifies each screen/state of the game; Game owns one GameState object per id
enum StateId
{
    MENU,
    PLAYING,
    PAUSED,
    INSTRUCTIONS_SCREEN,
    CREDITS_SCREEN,
    GAME_OVER,
    VICTORY,
    NUM_STATES
};

class GameState
{
public:
    virtual ~GameState() {}
    virtual void enter() {}
    virtual void exit() {}
    virtual void update(int deltaTime) = 0;
    virtual void render() = 0;
};
