//
// Created by chrissi-boi on 2020/11/09.
//

#include "Qualifying.h"

Qualifying::Qualifying(F1Car** array)
{
    for(int i = 0; i < 20; i++)
    {
        carArray[i] = array[i];
    }
}

F1Car** Qualifying::StartQualifying()
{
    for(int i = 0; i < 20; i++)
    {
        double randVal = ((rand() % 80 +1) + i) /100.0;
        this->carArray[i]->setQualifyingTime(randVal);
    }
    this->sortArray();
    return this->carArray;
}

void Qualifying::sortArray()
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < 20-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < 20; j++)
        {
            if (this->carArray[j]->getQualifyingTime() < this->carArray[min_idx]->getQualifyingTime())
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
