#include "Weapon.h"

Weapon::Weapon(const std::string& name, const std::string& ammo_name, int speed) 
    : m_name(name), m_ammo_name(ammo_name), m_speed(speed) {}