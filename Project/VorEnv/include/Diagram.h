#ifndef DIAGRAM_H
#define DIAGRAM_H

#include "Node.h"

class Diagram
{
public:
	Diagram();
	~Diagram();

	//functions
	void createNodes();
	void createDiagram();

	void render(sf::RenderWindow & window);

private:
	std::map<std::string, Node> m_nodes;
};

#endif // !DIAGRAM_H
