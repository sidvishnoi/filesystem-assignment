#include "../filesystem.h"

int FileSystem::undeleteFile(const char *title) {
    /*
     Objective: To a undelete a file
     Input parameters:
     title: File name
     Return:
     0: success
     1: error
     */
    TypeCastEntry entry;
    if (strlen(title) == 0) {
        // %% get file name from user in entry.entry.name
    } else {
        strcpy(entry.entry.name, title);
    }
    
    vector<int>position = alreadyExists(entry.entry.name, 'F');
    // %% use position to check if given file exists
    bool exists;
    if (!exists) {
        // %% display error message
        return 1;
    }
    
    char buffer[sectorSize_k];
    // %% read sector offset returned by alreadyExists() in "buffer"
    
    //reading file entry in entry.str
    for (int i = 0; i < 32; ++i) {
        entry.str[i] = buffer[position[1] + i];
    }
    
    int pos = entry.entry.startsAt;
    do {
        // reset status from deleted (negative) to normal (positive)
        int temp = (-1)*getStatus(pos);
        // %% change the status of "pos" to temp
        pos = temp;
    } while(pos != 1);
    
    //file marked undeleted
    entry.entry.type = 'f';
    
    // %% write the new updated entry at sector offset
    
    return 0;
}
