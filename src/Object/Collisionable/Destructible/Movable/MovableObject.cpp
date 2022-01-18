/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Raylib/Raylib.hpp"
#include "MovableObject.hpp"

MovableObject::MovableObject(const coords &pos, const coords &size, const std::pair<std::string, std::string> &path)
     : DestructibleObject(pos, size, path), _speed(3)
{
    _typeField.isMovable = true;
}

void MovableObject::move(const coords &direction) noexcept
{
    auto tmp = direction;
    tmp *= _speed * Raylib::getDeltaTime();
    _pos += tmp;
}

void MovableObject::rotate(float angle) noexcept
{
    _rotationAngle += angle;
    auto casted = static_cast<int>(_rotationAngle);
    auto moduloed = casted % 360;
    if (moduloed != casted)
        _rotationAngle = moduloed;
}

void MovableObject::increaseSpeed(float newSpeed)
{
    _speed += newSpeed;
}

void MovableObject::setSpeed(float speed)
{
    _speed = speed;
}

float MovableObject::getSpeed() const
{
    return _speed;
}
