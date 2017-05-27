#include "../filesystem.h"

int FileSystem::readFile(const char *title) {
    /*
     Objective: To a read a file
     Inpute parameters:
     title: File name
     Return type:	int
     0: success
     1: error
     */
    TypeCastEntry entry;
    if (strlen(title) == 0) {
        // %% get file name from user in entry.entry.name
    } else {
        strcpy(entry.entry.name, title);
    }
    
    vector<int>position;
    position=alreadyExists(entry.entry.name,'f');
    // %% use position to check if given file exists
    bool exists;
    if(!exists)
    {
        // %% dsplay error message
        return 1;
    }
    
    char buffer[sectorSize_k];
    // %% read sector offset returned by alreadyExists() in "buffer"
    
    //reading file entry in entry.str
    for( int i = 0 ; i < 32 ; ++i) entry.str[i] = buffer[position[1] + i];
    
    int sector = entry.entry.startsAt;
    while( sector!= 1 )
    {
        // %% Display content of sector
        sector = getStatus(sector);
    }
    return 0;
}
