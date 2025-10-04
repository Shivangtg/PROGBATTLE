#include <iostream>
#include "Game.h"
#include "SimpleBot.h"

int main() {
    try {
        Game game("maps/default.txt");
        
        // Find the spawn points from the map
        std::vector<Vec2D> spawnPoints = game.getSpawnPoints();

        // Make sure there are enough spawn points for our bots
        if (spawnPoints.size() < 2) {
            std::cerr << "Error: Not enough spawn points on the map for 2 bots." << std::endl;
            return 1;
        }

        // Create bots
        auto bot1 = std::make_unique<SimpleBot>();
        auto bot2 = std::make_unique<SimpleBot>();
        
        // Add tanks at the found spawn points
        game.addTank(std::move(bot1), spawnPoints[0]);
        game.addTank(std::move(bot2), spawnPoints[1]);

        game.run();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}