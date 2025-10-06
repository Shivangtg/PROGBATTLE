#pragma once
#include <string>
#include <variant>
#include <memory>
#include "Vec2D.h"
#include "Weapon.h"


struct ShootParams {
    Weapon weapon;
    Vec2D direction;
};

using ActionParams = std::variant<
    Vec2D,
    ShootParams,
    std::monostate
>;

class Action {
protected:
    std::string m_type;
public:
    Action(const std::string& type) : m_type(type) {}
    virtual ~Action() = default;
    std::string getType() const { return m_type; }
    virtual ActionParams getParams() const = 0;
};

class MoveAction : public Action {
private:
    Vec2D m_direction;
public:
    MoveAction(const Vec2D& dir) : Action("MOVE"), m_direction(dir) {}
    ActionParams getParams() const override { return m_direction; }
};

class ShootAction : public Action {
private:
    ShootParams m_params;
public:
    ShootAction(const ShootParams& params) : Action("SHOOT"), m_params(params) {}
    ActionParams getParams() const override { return m_params; }
};

class IdleAction : public Action {
public:
    IdleAction() : Action("IDLE") {}
    ActionParams getParams() const override { return std::monostate{}; }
};