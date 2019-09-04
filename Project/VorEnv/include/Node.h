#ifndef NODE_H
#define NODE_H

#include "MathHelper.h"
#include "Edge.h"

class Node
{
public:
	Node() { m_position = sf::Vector2f(); };
	Node(sf::Vector2f position) { m_position = position; m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius()); m_shape.setFillColor(sf::Color::White); m_shape.setPosition(position); m_shape.setRadius(2); };

	void updateNeighbours(std::string neighbour, Edge path) { m_neighours.insert(std::make_pair(neighbour, path)); };
	void render(sf::RenderWindow & window) { window.draw(m_shape); };


private:
	sf::CircleShape m_shape;
	sf::Vector2f m_position;
	std::map <std::string, Edge> m_neighours;
};

#endif // !NODE_H