#include "../filesystem.h"

int FileSystem::createDir(const char *title) {
    /*
     Objective: To create a new directory in current working directory
     Input parameters:
     title:  directory name
     Return value:
     0: success
     1: failure
     Effect: a new directory is created in filesystem and it's entry is passed in current working directory
     */
    
    TypeCastEntry entry;
    if (strlen(title) == 0) {
        // %% get file name from user and store it in entry.entry.name
    } else {
        strcpy(entry.entry.name, title);
    }
    
    /* %% use alreadyExists() to check for duplicate entry */
    bool dirAlreadyExists; // %%
    
    if (dirAlreadyExists) {
        cout << "ERROR: Directory <" <<
        entry.entry.name <<
        "> already exists!" << endl;
        return 1;
    }
    
    vector<int>offset = getEntryPosition();
    /* %% use offset to check if space for dir. entry is available */
    
    bool enoughSpaceForEntry;
    if(!enoughSpaceForEntry) {
        cout << "ERROR: Not enough space for directory entry." << endl;
        return 1;
    }
    
    vector<int> sectorsFree = findEmptySectors(sectorsForDir_k);
    // %% check if vector returned is empty
    
    bool enoughSectors;
    if (!enoughSectors) {
        cout << "ERROR: Not enough memory!" << endl;
        return 1;
    }
    
    /* %% fill details of dir. entry (parent, size, startsAt, type)
     Hint: entry.entry.type = 'd'
     entry.entry.startsAt = first sector we found free
     */
    
    // Directory entry
    writeEntry(offset, entry.str);
    
    for (int i = 0; i < sectorsForDir_k; ++i) {
        
        // we use index of next sector as status of sector to point next continuous location
        //   last sector's gets status = 1
        setStatus(sectorsFree[i], (i != sectorsForDir_k - 1) ? sectorsFree[i+1] : 1);
    }
    
    // %% display information about directory created
    return 0;
}
