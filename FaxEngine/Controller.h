#ifndef FAX_CONTROLLER_H
#define FAX_CONTROLLER_H

#include <map>
#include <SFML/Graphics.hpp>

#include "Connector.h"

namespace FAX {
	class Controller {
	protected:
		int nextConnectorKey;
		std::map<int, Connector> connectors;

	public:
		Connector createConnector();
		void render(sf::RenderWindow& window);
	};
}

#endif