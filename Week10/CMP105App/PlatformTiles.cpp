#include "PlatformTiles.h"

PlatformTiles::PlatformTiles()
{
	tileMap.loadTexture("gfx/marioTiles.png");
	GameObject tile;
	
	tileCenter= sf::Vector2f(getPosition().x + getSize().x / 2, getPosition().y + getSize().y / 2);
	std::vector<GameObject> tiles;
	for(int	i = 0; i < 7; i++)
	{
		tile.setSize(sf::Vector2f(32, 32));
		tile.setCollisionBox(0, 0, 32, 32);
		tile.setCollider(true);
		tiles.push_back(tile);
	}
	tiles[0].setCollider(false);
	tiles[0].setTextureRect
	(sf::IntRect(187, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));
	tiles[2].setTextureRect(sf::IntRect(17, 0, 16, 16));
	tiles[3].setTextureRect(sf::IntRect(34, 0, 16, 16));
	tiles[4].setTextureRect(sf::IntRect(0, 34, 16, 16));
	tiles[5].setTextureRect(sf::IntRect(17, 34, 16, 16));
	tiles[6].setTextureRect(sf::IntRect(34, 34, 16, 16));
	
	tileMap.setTileSet(tiles);
	

	// Map dimensions
	sf::Vector2u mapSize(13, 6);
	// build map
	std::vector<int> map = {
		1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 4, 5, 6, 1, 2, 3, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 4, 5, 6, 1, 2, 3, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0,
	};
	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 408));
	tileMap.buildLevel();


}

void PlatformTiles::renderMap(sf::RenderWindow* window)
{
	tileMap.render(window);
}

sf::Vector2f PlatformTiles::getCenter()
{
	return tileCenter;
}

void PlatformTiles::collision(Player* player)
{
	std::vector<GameObject>* world =tileMap.getLevel();
	for(int i = 0; i< (int)world->size(); i++)
	{
		// if collision check should occur
		if((*world)[i].isCollider())
		{
			if(Collision::checkBoundingBox(player, &(*world)[i]))
			{
				if (abs(player->getCenter().x - ((*world)[i].getPosition().x + (*world)[i].getSize().x /2)) < abs(player->getCenter().y - ((*world)[i].getPosition().y + (*world)[i].getSize().y / 2)))
				{
					player->collisionResponse(&(*world)[i]);
					player->isFalling = false;
					
				}
				else
				{
					
					player->setVelocity(0, 0);
					player->sideTouch = false;
				}
			}
			else
			{
				player->isFalling = true;
				player->sideTouch = false;
			}
		}
	}


}


