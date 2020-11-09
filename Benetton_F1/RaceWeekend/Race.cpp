//
// Created by chrissi-boi on 2020/11/09.
//

#include "Race.h"

#include <utility>

Race::Race(F1Car **array, Track* newTrack, vector<Tyre*> tyres)
{
    for(int i = 0; i < 20; i++)
    {
        this->carArray[i] = array[i];
    }
    this->track = newTrack;
    this->ourTyres = std::move(tyres);
}

F1Car **Race::StartRace()
{
    Tyre* tyre;
    vector<Tyre*>::iterator it;
    for(it = this->ourTyres.begin(); it < this->ourTyres.end(); it++)
    {
        tyre = (Tyre*) (*it);
    }

    for(int i = 0; i < this->track->getLaps(); i++)
    {
        for(int j = 0; j < 20; j++)
        {
            double randVal = ((rand() % 80 +1) + i - tyre->getPerformance()) /100.0;
            this->carArray[j]->setLapTime(randVal);
            double raceTime = this->carArray[j]->getRaceTime();
            double lapTime = this->carArray[j]->getLapTime();
            //cout << lapTime << endl;
            //cout << raceTime << endl;
            this->carArray[j]->setRaceTime(raceTime + lapTime);
            tyre->setWear(tyre->getWear()+(rand() % 10 +1));
        }
        this->sortArray();

        cout << "Lap " << i+1 << endl;
        for(int z = 0; z < 20; z++)
        {
            cout << this->carArray[z]->getCarName() << " RaceTime: " << this->carArray[z]->getRaceTime() << " minutes" << endl;
        }
        cout << endl;
    }
    return this->carArray;
}

void Race::sortArray()
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < 20-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < 20; j++)
        {
            if (this->carArray[j]->getRaceTime() < this->carArray[min_idx]->getRaceTime())
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        F1Car* temp = this->carArray[min_idx];
        this->carArray[min_idx] = this->carArray[i];
        this->carArray[i] = temp;
    }
}
