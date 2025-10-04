#include "SimpleBot.h"
#include "Game.h"
#include <cmath>
#include <limits>

std::unique_ptr<Action> SimpleBot::getAction(const Game& world) {
    const Tank& self = world.getTank(m_ownerId);
    const auto& allTanks = world.getTanks();
    
    Vec2D targetPos = {-1, -1};
    double min_dist = std::numeric_limits<double>::max();

    for (const auto& [id, other] : allTanks) {
        if (id == m_ownerId || !other.isAlive) continue;
        double dist = std::hypot(self.position.x - other.position.x, self.position.y - other.position.y);
        if (dist < min_dist) {
            min_dist = dist;
            targetPos = other.position;
        }
    }

    if (targetPos.x == -1) {
        return std::make_unique<MoveAction>(Vec2D{0, 1});
    }
    
    int dx = targetPos.x - self.position.x;
    int dy = targetPos.y - self.position.y;
    
    if (std::abs(dx) > std::abs(dy)) {
        return std::make_unique<MoveAction>(Vec2D{dx > 0 ? 1 : -1, 0});
    } else {
        return std::make_unique<MoveAction>(Vec2D{0, dy > 0 ? 1 : -1});
    }
}