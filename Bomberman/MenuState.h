#pragma once
#include "GameState.h"
#include "Text.h"
class MenuState :
    public GameState
{
public:
    MenuState();

    void enter() override;
    void exit() override;
    void update(int deltaTime) override;
    void render() override;

private:
    enum Option { PLAY, INSTRUCTIONS, CREDITS, QUIT, NUM_OPTIONS };

    void confirm();

    int selected;
    Text text;
};
