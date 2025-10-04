#include "Game.h"
#include "Bot.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <variant>

Game::Game(const std::string& mapPath) {
    std::ifstream file(mapPath);
    if (!file) {
        throw std::runtime_error("Could not open map file: " + mapPath);
    }
    std::string line;
    while (std::getline(file, line)) {
        m_grid.push_back(line);
    }
    m_height = m_grid.size();
    if (m_height > 0) {
        m_width = m_grid[0].size();
    }
    std::cout << "Map loaded: " << m_width << "x" << m_height << std::endl;
}

void Game::addTank(std::unique_ptr<Bot> botLogic, Vec2D startPos) {
    int newId = m_tanks.size() + 1;
    Weapon defaultWeapon("Basic Cannon", "Shell", 5);
    m_tanks.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(newId),
        std::forward_as_tuple(newId, 300, 100, startPos, defaultWeapon, std::move(botLogic))
    );
}

void Game::run() {
    while (!isGameOver()) {
        std::cout << "\n----- TICK " << m_tick << " -----" << std::endl;
        printState();

        auto actions = std::map<int, std::unique_ptr<Action>>();
        for (auto const& [id, tank] : m_tanks) {
            if (tank.isAlive) {
                actions[id] = tank.bot->getAction(*this);
            }
        }
        
        resolveActions(actions);
        updateState();

        m_tick++;
        if (m_tick > 50) {
            std::cout << "Max ticks reached!" << std::endl;
            break;
        }
    }
    std::cout << "\n----- GAME OVER -----" << std::endl;
    printState();
}

void Game::resolveActions(const std::map<int, std::unique_ptr<Action>>& actions) {
    for (auto const& [id, action] : actions) {
        if (!action) continue;
        Tank& tank = m_tanks.at(id);
        if (!tank.isAlive) continue;

        std::cout << "Tank " << id << " tries action: " << action->getType() << std::endl;
        if (action->getType() == "MOVE") {
            Vec2D dir = std::get<Vec2D>(action->getParams());
            Vec2D newPos = tank.position + dir;
            if (newPos.x >= 0 && newPos.x < m_width && newPos.y >= 0 && newPos.y < m_height && m_grid[newPos.y][newPos.x] != '#') {
                tank.position = newPos;
            }
        } else if (action->getType() == "SHOOT") {
            ShootParams params = std::get<ShootParams>(action->getParams());
            std::cout << "  -> Fired a " << params.bulletType << " bullet in direction (" << params.direction.x << "," << params.direction.y << ")" << std::endl;
        }
    }
}

void Game::updateState() {
    // This is where you would move bullets, check for collisions, etc.
}

bool Game::isGameOver() const {
    int aliveCount = 0;
    for (const auto& [id, tank] : m_tanks) {
        if (tank.isAlive) {
            aliveCount++;
        }
    }
    return aliveCount <= 1;
}

void Game::printState() const {
    std::vector<std::string> tempGrid = m_grid;
    for (const auto& [id, tank] : m_tanks) {
        if (tank.isAlive) {
            if(tank.position.y >= 0 && tank.position.y < tempGrid.size() && tank.position.x >=0 && tank.position.x < tempGrid[0].size()) {
               tempGrid[tank.position.y][tank.position.x] = std::to_string(id)[0];
            }
        }
    }
    for (const auto& row : tempGrid) {
        std::cout << row << std::endl;
    }
     for (const auto& [id, tank] : m_tanks) {
        if (tank.isAlive) {
            std::cout << "Tank " << id << ": HP=" << tank.hp << " AP=" << tank.ap << " Pos=(" << tank.position.x << "," << tank.position.y << ")" << std::endl;
        }
    }
}

std::vector<Vec2D> Game::getSpawnPoints() const {
    std::vector<Vec2D> points;
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            if (m_grid[y][x] == 'P') {
                points.push_back({x, y});
            }
        }
    }
    return points;
}