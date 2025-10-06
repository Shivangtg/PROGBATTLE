#pragma once
#include <string>
#include "Vec2D.h"

class Bullet{
    int m_source_id;
    std::string m_name;
    Vec2D m_position;
    Vec2D m_direction;
public:
    Bullet(int source_id, const std::string& name, const Vec2D& position, const Vec2D& direction );
    void Move();
    int getSource();
};

class Weapon {
private:
    int m_owner_id;
    int m_id;
    std::string m_name;
    Bullet m_bullet;
    int m_speed;

public:
    Weapon(int owner_id, int id, const std::string& name, const Bullet& bullet, int speed);
};

