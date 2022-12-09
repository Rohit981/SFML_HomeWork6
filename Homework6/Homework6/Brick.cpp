#include "Brick.h"

using namespace gm;
using namespace sf;

Brick::Brick()
{
}

Brick::Brick(const sf::Vector2f& position, const sf::Vector2f& size, const BrickType* type) : GameObject(position, size)
{
	this->type = type;
	this->size = size;
	health = type->health;
	score = type->score;
	body.setPosition(position);
	body.setFillColor(type->col);
	body.setSize(size);

	tex = type->tex;

	/*if (!normal_brick_tex->loadFromFile("Texture/brick.png"))
	{
		throw("Could not find the brick texture");
	}

	if (!cracked_brick_tex->loadFromFile("Texture/cracked brick.png"))
	{
		throw("Could not find the brick texture");
	}*/


	
}

Brick::~Brick()
{
}

void Brick::update(sf::RenderWindow& window, float deltaTime)
{
	body.setPosition(position);
	body.setSize(size);

	if (GetHealth() <= 0)
	{
		printf("Dead");
	}
}

void Brick::render(sf::RenderWindow& window, float deltaTime)
{
	window.draw(body);

}

void Brick::setPosition(const sf::Vector2f& position)
{
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Brick::setSize(const sf::Vector2f& size)
{
	GameObject::setSize(size);
	body.setSize(size);
}

void Brick::SetAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

const bool Brick::GetAlive() const
{
	return isAlive;
}

void Brick::SetHealth(const int health)
{
	this->health = health;
}

const int Brick::GetHealth() const
{
	return health;
}
