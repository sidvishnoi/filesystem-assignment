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
    /*
    example usage:
    getEntryPosition("somefile", 'f'):
        if exists already: return (current, b, true)
        else: return (sectorFree, byteFree, false)
    getEntryPosition('\0', 'f'):
        if exists (enough space): return (current, b, true)
        else: (not enough space): return (-1, -1, false)
    */
    int sectorOffset, byteOffset, alreadyExists;
    int sectorFree = -1, byteFree = -1;
    bool freeFound = false;
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
            if (!freeFound && strlen(cast.entry.name) == 0) {
                // used to return the offsets for free entry position
                sectorFree = current;
                byteFree = b;
                freeFound = true;
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
    vector<int> offsets = {sectorFree, byteFree, 0};
    return offsets;
}
