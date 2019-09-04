#include "Diagram.h"

Diagram::Diagram()
{
	std::srand(std::time(nullptr));
	createNodes();
}

Diagram::~Diagram()
{
}

void Diagram::createNodes()
{
	std::vector<sf::Vector2f> grid;
	std::vector<sf::Vector2f> active;
	std::vector<sf::Vector2f> ordered;

	int r = 25;
	int minimum = 200;
	int k = 30;
	int w = r / sqrt(2);
	int columns = std::floor(900 / w);
	int rows = std::floor(900 / w);

	for (int i = 0; i < columns * rows; i++)
	{
		grid.push_back(sf::Vector2f(-1, -1));
	}

	int x = 900 / 2;
	int y = 900 / 2;
	int a = std::floor((x / w));
	int b = std::floor((y / w));
	sf::Vector2f position = sf::Vector2f(x, y);
	grid[a + b * columns] = position;

	active.push_back(position);

	for (int total = 0; total < minimum; total++)
	{
		if (active.size() > 0)
		{
			int rand = sf::RandomInteger(1, active.size());
			sf::Vector2f position = active[rand - 1];
			bool found = false;

			for (int n = 0; n < k; n++)
			{
				sf::Vector2f prospect = sf::Vector2f(sf::RandomFloat(-900, 900), sf::RandomFloat(-900, 900));
				prospect = sf::Normalize(prospect);
				int mag = sf::RandomInteger(r, 2 * r);
				prospect = sf::Vector2f(prospect.x * mag, prospect.y * mag);
				prospect = sf::Vector2f(prospect.x + position.x, prospect.y + position.y);

				int col = prospect.x / w;
				int row = prospect.y / w;

				if (col >= 0 && row >= 0 && col <= columns && row <= rows && grid[col + row * columns] == sf::Vector2f(-1,-1))
				{
					bool valid = true;
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							int index = (col + i) + (row + j) * columns;
							if (index >= 0 && index <= columns * rows)
							{
								sf::Vector2f neighbour = grid[index];
								if (neighbour != sf::Vector2f(-1, -1))
								{
									float d = sf::Distance(prospect, neighbour);
									if (d < r)
									{
										valid = false;
									}
								}
							}
						}
					}

					if (valid)
					{
						found = true;
						grid[col + row * columns] = prospect;
						active.push_back(prospect);
						ordered.push_back(prospect);
					}
				}
			}
		}
	}

	for (int nodeIndex = 1; nodeIndex < ordered.size(); nodeIndex++)
	{
		m_nodes.insert(std::make_pair(std::to_string(nodeIndex), Node(ordered[nodeIndex])));
	}

	std::cout << m_nodes.size() << std::endl;
}

void Diagram::createDiagram()
{
}

void Diagram::render(sf::RenderWindow & window)
{
	for(std::pair<std::string, Node> node : m_nodes)
	{
		node.second.render(window);
	}
}
