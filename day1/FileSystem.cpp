#include "../filesystem.h"

// constructor
FileSystem::FileSystem(string title)
        : diskTitle_k(title) {

    // check if disk doesn't exists or is empty
    //  and if exists, get it's size in bytes

    /* %%
    >> write a code to check whether the disk already exists or not by checking it's size (store size in diskSize_k)
    and update the boolean variable
        alreadyExists = true, if file with same name exists
        else false
    */
    // %% logic here
    bool alreadyExists; // %%;

    // get size if not exists
    if (!alreadyExists) {
        int diskSizeMB;
        cout << "Enter disk size in MiB : ";
        cin >> diskSizeMB;
        cin.ignore(32767, '\n');
        diskSize_k = 1024*1024*diskSizeMB;
    }

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
