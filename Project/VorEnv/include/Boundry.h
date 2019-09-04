#ifndef BOUNDRY_H
#define BOUNDRY_H

#include "MathHelper.h"

class Boundry
{
public:
	inline Boundry() { m_line = std::make_pair(sf::Vector2f(), sf::Vector2f()); };
	inline Boundry(sf::Vector2f first, sf::Vector2f second) { m_line.first = first; m_line.second = second; };
	inline ~Boundry() { delete this; };

	inline std::pair<sf::Vector2f, sf::Vector2f> getLine() { return m_line; };
	inline void setLine(sf::Vector2f first, sf::Vector2f second) { m_line.first = first; m_line.second = second; };

private:
	std::pair<sf::Vector2f, sf::Vector2f> m_line;
};

#endif // !BOUNDRY_H