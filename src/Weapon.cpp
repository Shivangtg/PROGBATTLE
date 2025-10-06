#include "Weapon.h"

Weapon::Weapon(int owner_id, int id, const std::string& name, const Bullet& bullet, int speed) 
    :m_owner_id(owner_id), m_id(id), m_name(name), m_bullet(bullet), m_speed(speed) {}

void Weapon::fire(){

}




Bullet::Bullet(int source_id, const std::string& name, const Vec2D& position, const Vec2D& direction )
    : m_name(name), m_source_id(source_id), m_position(position), m_direction(direction) {}

void Bullet::Move(){
    m_position=m_position+m_direction;
}

int Bullet::getSource(){
    return m_source_id;
}