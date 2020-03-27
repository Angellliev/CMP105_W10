#pragma once
#include <iostream>
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
	sf::Texture playerTexture;
	bool hasJumped;
	
	
	sf::Vector2f playerCenter;
public:
	bool sideTouch;
	Player();
	void update(float dt);
	void playerMovement(float dt);
	void collisionResponse(GameObject* collider);
	sf::Vector2f getCenter();
	bool isFalling;
	void sideCollisionResponse(GameObject* collider);
};

