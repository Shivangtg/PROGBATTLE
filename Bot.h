#pragma once;

#include<string>


class Weapon{
    std::string m_name;
    std::string m_ammo_name;
    int m_speed;
public:
    Weapon(const std::string& name, const std::string& ammo_name, int speed);
};




class Bot{
    std::string m_bot_id;
    Weapon m_weapon;
    int m_health;
public:
    Bot(const std::string& id, const Weapon& weapon, int health);
};
