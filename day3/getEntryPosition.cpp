#include "../filesystem.h"

vector<int> FileSystem::getEntryPosition() {
    /*
    Objective: return the offsets for free position for file/directory entry
    Input Parameters:
        None
    return:
        vector [sectorOffset, byteOffset] if space available
            else: [-1, -1]
    */
    char buffer[sectorSize_k];
    TypeCastEntry cast;

    // start looking from first non-reserved sector
    // (or current working directory)
    int current = reservedSectors_k;
    for (int s = 0; s < sectorsForDir_k; ++s) {
        readSector(current, buffer);
        for (int b = 0; b < sectorSize_k; b += 32) {
            for (int k = 0; k < 32; ++k) {
                cast.str[k] = buffer[b+k];
            }
            if (strlen(cast.entry.name) == 0) {
                // found free space
                vector<int> offsets = {current, b};
                return offsets;
            }
        }
        // next sector to look in
        current = getStatus(current);
    }
    // no position found
    vector<int> offsets = {-1, -1};
    return offsets;
}
