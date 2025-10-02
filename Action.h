#pragma once

#include <string>
#include <variant>

struct shoot_params{
    std::string weapon;
    std::string ammo;
    int speed;
    std::pair<int,int> direction;
};


using ActionParams = std::variant<
    std::string,            //for Move
    std::pair<int,int>,     //for Fog
    shoot_params            //for Shoot
>;








class Action {
protected:
    std::string m_type;
public:
    Action(const std::string& type);
    virtual ~Action() = default;
    virtual std::string get_type() const;
    virtual ActionParams get_params() const = 0;
};





//Move Action
class MoveAction : public Action {
    std::string m_direction;
public:
    MoveAction(const std::string& type, const std::string& dir);
    ActionParams get_params() const override;
};



//Shoot Action
class ShootAction : public Action {
    std::string m_weapon;
    std::string m_ammo;
    int m_speed;
    std::pair<int,int> m_direction;
public:
    ShootAction(const std::string& type, const std::string& weapon, const std::string& ammo, int speed, const std::pair<int,int>& direction);
    ActionParams get_params() const override;
};



//Fog Action
class FogAction : public Action {
    std::pair<int,int> m_spot;
public:
    FogAction(const std::string& type, std::pair<int,int>& direction);
    ActionParams get_params() const override;
};

