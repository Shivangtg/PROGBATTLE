#include "Action.h"

// Base constructor
Action::Action(const std::string& type) : m_type(type) {}

std::string Action::get_type() const {
    return m_type;
}





// MoveAction constructor
MoveAction::MoveAction(const std::string& type, const std::string& dir)
    : Action(type), m_direction(dir) {}

// MoveAction functions
ActionParams MoveAction::get_params() const {
    return m_direction;
}


// ShootAction constructor
ShootAction::ShootAction(const std::string& type, const std::string& weapon, const std::string& ammo, int speed, const std::pair<int,int>& direction) : Action(type), m_weapon(weapon), m_ammo(ammo), m_speed(speed), m_direction(direction) {}

// ShootAction functions
ActionParams ShootAction::get_params() const {
    shoot_params a{
        m_weapon,m_ammo,m_speed,m_direction
    };
    return a;
}

// FogAction constructor
FogAction::FogAction(const std::string& type, const std::pair<int,int>& spot) : Action(type), m_spot(spot) {}

// FogAction functions
ActionParams FogAction::get_params() const {
    
    return m_spot;
}