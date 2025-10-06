#pragma once
#include <string>
#include <memory>
#include "Vec2D.h"
#include "Weapon.h"

class Bot; 

class Tank {
public:
    int id;
    int hp;
    int ap;
    Vec2D position;
    Vec2D direction;
    Weapon weapon;
    std::unique_ptr<Bot> bot;
    bool isAlive = true;

    Tank(int id, int startHp, int startAp, Vec2D startPos, Weapon startingWeapon, std::unique_ptr<Bot> botLogic);
    void takeDamage(int amount);
    void fire();
    void move();
    void usePowerUp();
};