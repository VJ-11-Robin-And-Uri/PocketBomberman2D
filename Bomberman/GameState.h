#pragma once
class GameState
{
public:
    virtual ~GameState() {}
    virtual void enter() {}
    virtual void exit() {}
    virtual void update(int deltaTime) = 0;
    virtual void render() = 0;
};
