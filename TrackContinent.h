#ifndef TRACKCONTINENT_H
#define TRACKCONTINENT_H

class TrackContinent : Track {

public:
	Track* continent;

	TrackContinent();

	void add(Track* continent);
};

#endif
