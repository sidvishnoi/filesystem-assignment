#include "../filesystem.h"

void FileSystem::createDisk()
{
    /*
    objective: reserves disk space by writing numberOfSectors_k sectors of size sectorSize_k each
    */
    char buffer[sectorSize_k];

    // create a buffer of size sectorSize_k
    for (int i = 0; i < sectorSize_k; ++i)
    {
        buffer[i] = '0';
    }

    // reserve disk space by writing numberOfSectors_k sectors
    for (int i = 0; i < numberOfSectors_k; ++i)
    {
        writeSector(i, buffer);
    }

}