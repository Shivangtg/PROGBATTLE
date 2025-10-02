#include "Bot.h"
//Weapons constructor
Weapon::Weapon(const std::string& name, const std::string& ammo_name, int speed) : m_name(name),m_ammo_name(ammo_name),m_speed(speed){}

Bot::Bot(const std::string& id, const Weapon& weapon, int health) : m_bot_id(id), m_weapon(weapon), m_health(health) {};