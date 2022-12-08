#include "GameObject.h"

using namespace sf;
using namespace gm;

// Default constructor
GameObject::GameObject() {}

// Overloaded constructor that takes a position
// NOTE that we set the position using the initialization list
GameObject::GameObject(const Vector2f& position, const Vector2f& size) : position(position), collider(position, size) {}


// Our position getter, NOTE the const reference return and marking the method itself const
const Vector2f& GameObject::getPosition() const
{
	return position;
}

const sf::Vector2f& gm::GameObject::getSize() const
{
	return size;
}

// Our position setter, takes a Vector2f by const reference
void GameObject::setPosition(const Vector2f& position)
{
	this->position = position;

	collider.top = position.y;
	collider.left = position.x;


}

void gm::GameObject::setSize(const sf::Vector2f& size)
{
	this->size = size;

	collider.height = size.y;
	collider.width = size.x;
}

// Moves our game object relative to its current position
void GameObject::move(const Vector2f& velocity) {
	setPosition(position + velocity);
}

// Returns a constant reference to the float rect used in collision detection
const FloatRect& GameObject::getCollider() const {
	return collider;
}

// Checks to see if the float rect collider contains a specified point
bool GameObject::collide(const Vector2f& point) const {
	return collider.contains(point);
}

// Checks to see if the float rect collider intersects another float rect
bool GameObject::collide(const FloatRect& rect) const {
	return collider.intersects(rect);
}