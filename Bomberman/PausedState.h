#pragma once
#include "GameState.h"

class PlayingState;

class PausedState :
    public GameState
{
public:
    PausedState(PlayingState *playing);

    void enter() override;
    void update(int deltaTime) override;
    void render() override;

private:
    enum Option { RESUME, BACK_TO_MENU, NUM_OPTIONS };

    void confirm();

    PlayingState *playing; // Not owned: drawn frozen underneath the pause menu
    int selected;
};
