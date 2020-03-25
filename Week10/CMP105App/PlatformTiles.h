#pragma once
#include "Framework/TileMap.h"
#include "Framework/GameObject.h"
class PlatformTiles : public GameObject
{
	TileMap tileMap;
	public:
		PlatformTiles();
		void renderMap(sf::RenderWindow* window);
};

