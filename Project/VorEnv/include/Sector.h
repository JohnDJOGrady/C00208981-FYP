#ifndef SECTOR_H
#define SECTOR_H

#include "MathHelper.h"
#include "Boundry.h"

class Sector
{
public:
	Sector() { m_resources = 0.0f; m_capacity = 0; };
	~Sector() {};

	void render(sf::RenderWindow & window);

private:
	float m_resources;
	int m_capacity;
	std::vector<Boundry> m_boundries;
};

#endif // !SECTOR_H