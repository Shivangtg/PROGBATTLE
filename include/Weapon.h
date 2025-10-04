#pragma once
#include <string>

class Weapon {
private:
    std::string m_name;
    std::string m_ammo_name;
    int m_speed;

public:
    Weapon(const std::string& name, const std::string& ammo_name, int speed);
};