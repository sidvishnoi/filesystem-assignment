#include "../filesystem.h"

vector<int> FileSystem::alreadyExists(char *name, char type) {
    /*
     Objective: To check whether a file/dir already exists in current working directory
     Input Parameters:
        name: dir/file name
        type: type (d = dir, f = file)
     Return value: vector<int>
        {-1,-1,0} if not found
        {sector_offset, byte_offset, 1} otherwise
     */
    TypeCastEntry cast;
    char buffer[sectorSize_k];
    int next = reservedSectors_k;
    for(int count = 0; count < sectorsForDir_k; ++count) {
        readSector(next, buffer);
        for (int i = 0; i < sectorSize_k/32; ++i) {
            for (int j = 0; j < 32; ++j) {
                cast.str[j] = buffer[32*i + j];
            }
            // %% check if file with same characteristics exists
            if (true /* %%  CONDITION */) {
                vector<int> offset = {next, 32*i, 1};
                return offset;
            }
        }
        next = getStatus(next);
    }
    vector<int> offset = {-1,-1,0};
    return offset;
}
