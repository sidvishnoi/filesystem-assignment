#include "../filesystem.h"

int FileSystem::deleteFile(const char *title) {
    /*
     Objective: To a delete a file or remove it if already deleted
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
    
    vector<int> position = alreadyExists(entry.entry.name, 'f');
    // %% use position to check if given file exists
    bool exists;
    if(!exists) {
        position = alreadyExists(entry.entry.name,'F');
        // %% check if still not found
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
    
    if(entry.entry.type == 'f') {
        do {
            int temp = getStatus(pos);
            // %% change the status of "pos" to its (-)ve
            pos = temp;
        } while(pos != 1);
        
        // file marked deleted
        entry.entry.type = 'F';
        
        // %% write the new updated entry at sector offset
        // %% print successful marked deleted message
        return 0;
    }
    
    // %% check if file is already deleted
    bool alreadyDeleted;
    
    // removing file permanently
    if (alreadyDeleted) {
        // %% repeat the procedure to delete a file (and set status with 0 for every sector occupied by file to mark it as free)
        
        //deleting file entry
        for (int i = 0; i < 32; ++i) {
            buffer[position[1] + i] = '\0';
        }
        
        // %% write the buffer at sector offset
        // %% print permanent delete message
        return 0;
    }
    return 1;
}
