#include "Tank.h"
#include "Bot.h"

Tank::Tank(int id, int startHp, int startAp, Vec2D startPos, Weapon startingWeapon, std::unique_ptr<Bot> botLogic)
    : id(id), 
      hp(startHp), 
      ap(startAp), 
      position(startPos), 
      weapon(startingWeapon), 
      bot(std::move(botLogic)) 
{
    this->bot->setOwnerId(id);
}

void Tank::fire(){
    
}

void Tank::takeDamage(int amount) {
    hp -= amount;
    if (hp <= 0) {
        hp = 0;
        isAlive = false;
        std::cout << "Tank " << id << " has been destroyed!" << std::endl;
    }
}