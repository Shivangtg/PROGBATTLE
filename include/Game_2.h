#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "Tank.h"
#include "Action.h"
#include "Grid.h"


class Game {
private:
    int m_tick = 0;
    int m_width = 0;
    int m_height = 0;
    Grid m_grid;
    std::map<int, Tank> m_tanks;

public:

    Grid gridForBots();

    void resolveActions(std::vector<Action> actions); //logically updates the grid like changing the internal states of various entities on grid based on their actions

    void updateGrid(); //updates the grid object based on the actions taken by the bots

};