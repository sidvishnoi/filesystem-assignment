#include "../filesystem.h"

vector<int> FileSystem::findEmptySectors(int requiredNumber) {
    /*
    Objective: To get a list of sectors that are available to be written on
    Input Parameters:
        requiredNumber: Number of empty sectors required
    Return Value:
        list of available sectors
        if not enough available, return empty list
    */
    TypeCastInt cast;
    vector<int> availableSectors;
    int found = 0, sector = 0;
    int div = sectorSize_k/4;   // each sector contains status of this much sectors
    char buffer[sectorSize_k];
    while (found != requiredNumber && sector < reservedSectors_k) {
        readSector(sector, buffer);
        for (int s = 0; s < div; ++s) {
            for (int j = 0; j < 4; ++j) {
                cast.str[j] = buffer[4*s + j];
            }
            if (cast.num == FREE) {
                availableSectors.push_back(s + reservedSectors_k + sector*div);
                ++found;
            }
            if (found == requiredNumber) break;
        }
    ++sector;
    }

    // if still, found != requiredNumber, now try looking in DELETED sectors (DAY 4)
    // %% look in sectors marked deleted here

    if (found != requiredNumber) {
        // empty list if enough sectors are not available (failure)
        availableSectors.empty();
    }
    return availableSectors; // success
}
