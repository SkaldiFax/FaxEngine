#ifndef FAX_ENTITY_H
#define FAX_ENTITY_H

#include <map>

#include "Connector.h"

namespace FAX {
	class Entity {
	protected:
		int nextConnectorKey;
		std::map<int, Connector> connectors;

	public:
		int registerConnector(const Connector& connector);
	};
}

#endif