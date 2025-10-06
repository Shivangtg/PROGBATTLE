#include "Grid.h"

bool Grid::isFogged(int x, int y) const {
    std::size_t index = y * width + x;
    return (fogBits[index / 8] >> (index % 8)) & 1;
}

void Grid::setFog(int x, int y, bool fogged) {
    std::size_t index = y * width + x;
    if (fogged)
        fogBits[index / 8] |= (1 << (index % 8));
    else
        fogBits[index / 8] &= ~(1 << (index % 8));
}

TileType Grid::getTileType(int x,int y) const {
    int index = y * width + x;
    return staticLayer[index];
}

void Grid::setTile(int x, int y, TileType type) {
    int index = y * width + x;
    staticLayer[index] = type;
}

std::vector<Entity>& Grid::entitiesAt(int x, int y) {
    Vec2D v;
    v.x = x;
    v.y = y;
    return entityLayer[v];
}

