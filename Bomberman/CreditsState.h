#pragma once
#include "GameState.h"

class CreditsState :
    public GameState
{
public:
    void enter() override;
    void update(int deltaTime) override;
    void render() override;
};
