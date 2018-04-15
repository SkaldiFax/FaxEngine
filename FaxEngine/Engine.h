#ifndef FAX_ENGINE_H
#define FAX_ENGINE_H

#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Controller.h"
#include "Connector.h"

namespace FAX {
	class Engine {
	protected:
		sf::RenderWindow window;
		sf::Clock updateClock;
		float runTime;
		int runFrames;

		int nextEntityKey;
		std::map<int, Entity> entities;

		int nextControllerKey;
		std::map<int, Controller> controllers;

	public:
		void initialize();
		void run();
		int createEntity();
		int createController();
		void linkEntityToController(int entityKey, int controllerKey);
	};
}

#endif