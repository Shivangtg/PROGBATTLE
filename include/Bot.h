#pragma once
#include <memory>
#include <vector>
#include "Action.h"

class Tank;
class Game;

class Bot {
protected:
    int m_ownerId = -1;
public:
    virtual ~Bot() = default;
    void setOwnerId(int id) { m_ownerId = id; }
    virtual std::unique_ptr<Action> getAction(const Game& world) = 0;
};