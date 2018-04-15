#include "stdafx.h"
#include "Engine.h"

namespace FAX {
	void Engine::initialize() {
		window.create(
			sf::VideoMode(1080, 720),
			"FaxEngine",
			sf::Style::None
		);

		updateClock = sf::Clock();

		nextEntityKey = 0;
		entities = std::map<int, Entity>();
	}

	void Engine::run() {
		updateClock.restart();

		int entityKey = createEntity();
		int controllerKey = createController();
		linkEntityToController(entityKey, controllerKey);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				else if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
				}
			}

			float updateInterval = updateClock.restart().asSeconds();
			runTime += updateInterval;
			++runFrames;

			window.clear(sf::Color::Black);
			for (auto& controllerPair : controllers) {
				controllerPair.second.render(window);
			}
			window.display();
		}
	}

	int Engine::createEntity() {
		Entity newEntity;
		entities.insert(std::pair<int, Entity>(nextEntityKey, newEntity));
		return nextEntityKey++;
	}

	int Engine::createController() {
		Controller newController;
		controllers.insert(std::pair<int, Controller>(nextControllerKey, newController));
		return nextControllerKey++;
	}

	void Engine::linkEntityToController(int entityKey, int controllerKey) {
		Entity& entity = entities.at(entityKey);
		Controller& controller = controllers.at(controllerKey);
		const Connector& newConnector = controller.createConnector();
		entity.registerConnector(newConnector);
	}
}