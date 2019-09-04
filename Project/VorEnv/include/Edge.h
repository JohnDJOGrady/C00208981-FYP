#ifndef EDGE_H
#define EDGE_H

#include "MathHelper.h"

class Edge
{
public:
	inline Edge() { m_edge = std::make_pair("", ""); m_weight = 0.0f; };
	inline Edge(std::string origin, std::string destination) { m_edge.first = origin; m_edge.second = destination; };
	~Edge() { delete this; };

	inline float getWeight() { return m_weight; };
	inline void setWeight(float weight) { m_weight = weight; };

	void render(sf::RenderWindow & window);

private:
	std::pair<std::string, std::string> m_edge; // origin then destination
	float m_weight; // user defined - its difficulty
};

#endif // !EDGE_H