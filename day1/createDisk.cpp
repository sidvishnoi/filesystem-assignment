#include "../filesystem.h"

void FileSystem::createDisk()
{
    /*
    objective: reserves disk space by writing numberOfSectors_k sectors of size sectorSize_k each
    */
    ofstream fp;
    fp.open(diskTitle_k, ios::binary | ios::out);
    fp.close();
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

    // reserve space for root directory
    for (int i = numberOfSectors_k; i < numberOfSectors_k + sectorsForDir_k; ++i)
    {
        int s = (i == sectorsForDir_k - 1) ? 1 : i+1;
        setStatus(i, s);
    }

}
