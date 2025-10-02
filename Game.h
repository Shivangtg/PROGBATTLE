#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "Action.h"
#include "Bot.h"


class Game {
    int tick;
    std::vector<std::string> grid;
    std::unordered_map<Bot,Action> prev_action_map;
public:

    void updateGrid(const std::vector<std::unique_ptr<Action>>& moves);

};

#endif
