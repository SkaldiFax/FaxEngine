#include "stdafx.h"
#include "Controller.h"

namespace FAX {
	Connector Controller::createConnector() {
		Connector newConnector;
		connectors.insert(std::pair<int, Connector>(nextConnectorKey, newConnector));
		return newConnector;
	}

	void Controller::render(sf::RenderWindow& window) {
		for (auto& connector : connectors) {
			sf::CircleShape shape(50);
			shape.setFillColor(sf::Color(100, 250, 50));
			window.draw(shape);
		}
	}
}
