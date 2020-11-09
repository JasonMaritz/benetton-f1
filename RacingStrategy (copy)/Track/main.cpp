#include<iostream>
#include<string>
using namespace std;
#include "Track.h"
#include "TrackContinent.h"
#include "RaceCategory.h"
#include "africa.h"
#include "Asia.h"
#include "Europe.h"
#include "SAmerica.h"
#include "NAmerica.h"
#include "European.h"
#include "NonEuropean.h"


int main(){

	cout<<"Welcome to african RaceTrack!!!"<<endl;
	Track* myTrack;
	myTrack = new TrackContinent();
	myTrack->add(new africa());
	myTrack->add(new NonEuropean());
	cout << "Laps = " << myTrack->trackLaps() << endl;

			myTrack->generateReport() ;
	delete myTrack;

	cout<<"Welcome to Europe RaceTrack!!!"<<endl;
		Track* myTrack1;
		myTrack1 = new TrackContinent();
		myTrack1->add(new Europe());
		myTrack->add(new European());
		cout << "length of the Tack  = " << myTrack1->trackLength() << endl;
		delete myTrack1;

		cout<<"Welcome to south America RaceTrack!!!"<<endl;
			Track* myTrack2;
			myTrack2 = new TrackContinent();
			myTrack2->add(new SAmerica());
			myTrack->add(new NonEuropean());
			cout << "Wear factor = " << myTrack2->trackWear() << endl;
			delete myTrack2;

			cout<<"Welcome to North American RaceTrack!!!"<<endl;
				Track* myTrack4;
				myTrack4 = new TrackContinent();
				myTrack4->add(new NAmerica());
				myTrack->add(new NonEuropean());
				cout << "number of corners  = " << myTrack4->trackCorner() << endl;
				cout << "city  = " << myTrack4->trackCity() << endl;
				delete myTrack4;





	return 0;
}
