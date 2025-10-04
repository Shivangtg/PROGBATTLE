#pragma once
#include "Bot.h"

class SimpleBot : public Bot {
public:
    std::unique_ptr<Action> getAction(const Game& world) override;
};