#pragma once
#include "Framework/TileMap.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include "Framework/Collision.h"
class PlatformTiles : public GameObject
{
	TileMap tileMap;
	sf::Vector2f tileCenter;
	Player plr;
	public:
		
		PlatformTiles();
		void renderMap(sf::RenderWindow* window);
		sf::Vector2f getCenter();
		void collision(Player* player);
};

