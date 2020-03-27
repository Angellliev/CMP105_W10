#include "Player.h"

Player::Player()
{
	hasJumped = true;
	isFalling = true;
	
	playerTexture.loadFromFile("gfx/MushroomTrans.png");
	setSize(sf::Vector2f(32, 32));
	setTexture(&playerTexture);
	setCollisionBox(0, 0, getSize().x, getSize().y);
	
}

void Player::update(float dt)
{
	playerMovement(dt);
	playerCenter = sf::Vector2f(getPosition().x + getSize().x / 2, getPosition().y + getSize().y / 2);
	std::cout << getPosition().y << std::endl;
	if (isFalling)
	{
		velocity.y += 1;
	}
	
		
	
	
	move(velocity * dt);
	
}

void Player::playerMovement(float dt)
{

	if (input->isKeyDown(sf::Keyboard::A))
		{
			velocity.x = -100;
		}
	else if (input->isKeyDown(sf::Keyboard::D))
		{
			velocity.x = 100;
		}
	else
		{
			velocity.x = 0;
		}
	

	if (input->isKeyDown(sf::Keyboard::Space) && !hasJumped)
	{
		velocity.y = -500;
		hasJumped = true;
	}
}



void Player::collisionResponse(GameObject* collider)
{
	velocity.y = 0;
	isFalling = false;
	hasJumped = false;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}

sf::Vector2f Player::getCenter()
{
	return playerCenter;
}

void Player::sideCollisionResponse(GameObject* collider)
{
	
	
	
}
