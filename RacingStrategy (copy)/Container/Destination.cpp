#include "Destination.h"

Destination::Destination() {}

Destination::Destination(Destination* d) {
	startDate = d->startDate;
	endDate = d->endDate;
	location = d->location;
}