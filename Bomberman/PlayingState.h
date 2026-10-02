#pragma once
#include "GameState.h"
#include "Scene.h"

class PlayingState :
    public GameState
{
public:
    PlayingState();

    void enter() override;
    void update(int deltaTime) override;
    void render() override;

private:
    Scene scene;
};
