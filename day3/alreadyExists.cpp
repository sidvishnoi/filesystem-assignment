#include "../filesystem.h"

bool FileSystem::alreadyExists(char *name, char type) {
    /*
    Objective: To check whether a file/dir already exists in current working directory
    Input Parameters:
        name: dir/file name
        type: type (d = dir, f = file)
    Return value: bool
        true : if file/dir already exists
        false : else
    */
    TypeCastEntry entry;
    char buffer[sectorSize_k];
    int next = reservedSectors_k;
    for(int count = 0; count < sectorsForDir_k ; ++count) {
        readSector(next, buffer);
        for (int i = 0; i < sectorSize_k/32; ++i) {
          for (int j = 0; j < 32; ++j) {
                entry.str[j] = buffer[32*i + j];
          }
            // %% check if file with same characteristics exists
            if (true /* %%  CONDITION */) {
                return true;
            }
        }
        next = getStatus(next);
    }
    return false;
}
