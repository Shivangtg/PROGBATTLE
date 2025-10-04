#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "Tank.h"
#include "Action.h"

class Game {
private:
    int m_tick = 0;
    int m_width = 0;
    int m_height = 0;
    std::vector<std::string> m_grid;
    std::map<int, Tank> m_tanks;

    void resolveActions(const std::map<int, std::unique_ptr<Action>>& actions);
    void updateState();
    bool isGameOver() const;

public:
    Game(const std::string& mapPath);
    void addTank(std::unique_ptr<Bot> botLogic, Vec2D startPos);
    void run();
    void printState() const;
    
    // Getters for bot AI
    const std::map<int, Tank>& getTanks() const { return m_tanks; }
    const Tank& getTank(int id) const { return m_tanks.at(id); }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    // Helper to find spawn points on the map
    std::vector<Vec2D> getSpawnPoints() const;
};