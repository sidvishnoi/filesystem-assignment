#include "../filesystem.h"

int FileSystem::readFile(const char *title) {
    /*
    Objective: To a read a file
    Input parameters:
        title: File name
    Return:
        0: success
        1: error
    Output: contents of file
    */
    TypeCastEntry entry;
    if (strlen(title) == 0) {
        // %% get file name from user in entry.entry.name
    } else {
        strcpy(entry.entry.name, title);
    }

    vector<int>position = alreadyExists(entry.entry.name, 'f');
    // %% use position to check if given file exists
    bool exists;
    if(!exists) {
        // %% display error message
        return 1;
    }

    char buffer[sectorSize_k];
    // %% read sector offset returned by alreadyExists() in "buffer"

    //reading file entry in entry.str
    for( int i = 0 ; i < 32 ; ++i) entry.str[i] = buffer[position[1] + i];

    int sector = entry.entry.startsAt;
    while (sector != 1) {
        // %% Display content of sector
        sector = getStatus(sector);
    }
    return 0;
}
