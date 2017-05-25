#include "../filesystem.h"

// constructor
FileSystem::FileSystem(
    string title = "Disk.bin", // default title for disk
        int diskSize = 1024*1024, // 1Mib = 1024*1024 bytes (default)
        bool alreadyExists = false) :
        diskTitle_k(title),
        diskSize_k(diskSize) {

    /* %%
    how many sectors of each size sectorSize_k exist, if total disk size = diskSize_k
    >> update right hand value for numberOfSectors_k
    */
    numberOfSectors_k = -1;

    /* %%
    how many sectors need to be reserved, if each sector needs 4 bytes (sizeof int) to store a status?
    >> update right hand value for reservedSectors_k
    */
    reservedSectors_k = -1;

    // reserve space, if disk doesn't already exist
    if (!alreadyExists) createDisk();
}