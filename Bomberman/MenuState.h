#pragma once
#include "GameState.h"
class MenuState :
    public GameState
{
public:
    void enter() override;
    void exit() override;
    void update(int deltaTime) override;
    void render() override;

private:
    enum Option { PLAY, INSTRUCTIONS, CREDITS, QUIT, NUM_OPTIONS };

    void confirm();

    int selected;
};

