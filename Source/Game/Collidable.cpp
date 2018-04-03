#include "Collidable.h"

Collidable::Collidable(float width, float height)
    : m_size    (width, height)
{}

bool Collidable::tryCollideWith(Collidable & other)
{
    if (getBox().intersects(other.getBox())) {
        onCollide();
        other.onCollide();
        return true;
    }
    return false;
}

sf::FloatRect Collidable::getBox() const
{
    return
    {
        getPosition().x,
        getPosition().y,
        m_size.x,
        m_size.y
    };
}
