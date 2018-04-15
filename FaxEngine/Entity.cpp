#include "stdafx.h"
#include "Entity.h"

namespace FAX {
	int Entity::registerConnector(const Connector& connector) {
		connectors.emplace(nextConnectorKey, connector);
		return nextConnectorKey++;
	}
}