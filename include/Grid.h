//Grid will consist of three layers
//1.Static layer
//2.Entity layer
//3.Visibility layer

#pragma once
#include <vector>
#include <unordered_map>
#include "Vec2D.h"

enum class TileType : uint8_t {
    Empty,
    Wall,
    Obstacle
};

struct Entity {
    enum class Type { Bullet, Bot, Weapon };
    Type type;
    int id;
};
struct PositionHash {
    std::size_t operator()(const Vec2D& pos) const noexcept {
        return (pos.x * 73856093) ^ (pos.y * 19349663);
    }
};




class Grid {
    int width, height;
    std::vector<uint8_t> fogBits;
    std::vector<TileType> staticLayer;
    std::unordered_map<Vec2D, std::vector<Entity>, PositionHash> entityLayer;

public:
    Grid(int w, int h)
        : width(w), height(h),
          fogBits((w*h + 7) / 8, 0),
          staticLayer(w*h, TileType::Empty) {}

    // accessors
    bool isFogged(int x, int y) const;
    void setFog(int x, int y, bool fogged);
    TileType getTileType(int x, int y) const;
    void setTile(int x, int y, TileType type);
    std::vector<Entity>& entitiesAt(int x, int y);
};
