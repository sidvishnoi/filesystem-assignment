#include "../filesystem.h"

vector<int> FileSystem::getEntryPosition(char *title, char type) {
    /*
    Objective: return the offsets for a directory/file entry based on title and type
    Input Parameters:
        title: title for entry (if empty, looks for available location)
        type: type of entry (f: file, d: directory)
    return:
        vector (sectorOffset, byteOffset, alreadyExists(1: true))
    */
    int sectorOffset, byteOffset, alreadyExists;
    char buffer[sectorSize_k];
    TypeCastEntry cast;

    // start looking from first non-reserved sector
    int current = reservedSectors_k;
    for (int s = 0; s < sectorsForDir_k; ++s) {
        readSector(current, buffer);
        for (int b = 0; b < sectorSize_k; b += 32) {
            for (int k = 0; k < 32; ++k) {
                cast.str[k] = buffer[b+k];
            }
            if (strcmp(cast.entry.name, title) == 0 && cast.entry.type == type) {
                // found position
                vector<int> offsets = {current, b, 1};
                return offsets;
            }
        }
        // next sector to look in
        current = getStatus(current);
    }
    // no such entry found
    vector<int> offsets = {-1, -1, 0};
    return offsets;
}
