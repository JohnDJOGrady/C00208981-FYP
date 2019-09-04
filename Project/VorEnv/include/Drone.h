#ifndef DRONE_H
#define DRONE_H

#include "MathHelper.h"

class Drone
{
public:
	Drone() {};
	~Drone() {};


	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;

};

#endif // !DRONE_H