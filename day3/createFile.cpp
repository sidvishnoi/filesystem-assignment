#include "../filesystem.h"

#ifndef MAX_FILE_SIZE
#define MAX_FILE_SIZE 1024
#endif

int FileSystem::createFile(const char *title, const char *srcFile) {
    /*
     Objective: To create a file
     Input parameters:
     title:  file name
     srcfile: file to read data from
     Return value:
     0: success
     1: failure
     Effect: a new file is created in filesystem and it's entry is passed in current working directory
     */
    
    TypeCastEntry entry;
    if (strlen(title) == 0) {
        // %% get file name from user and store it in entry.entry.name
    } else {
        strcpy(entry.entry.name, title);
    }
    
    /* %% use alreadyExists() to check for duplicate entry) */
    bool fileAlreadyExists; // %%
    
    if(fileAlreadyExists) {
        cout << "ERROR: File <" << entry.entry.name<< "> already exists!" << endl;
        return 1;
    }
    
    vector<int>offset = getEntryPosition();
    
    /* %% use offset to check if space for file entry is available */
    bool enoughSpaceForEntry;
    if(enoughSpaceForEntry) {
        cout << "ERROR: Not enough space for file entry." << endl;
        return 1;
    }
    
    // file contents & size
    char file_content[MAX_FILE_SIZE];
    
    if (strlen(srcFile) == 0) {
        // if source file is not given
        // %% get data from user into file_content and calculate size in bytes to entry.entry.size
    } else {
        ifstream fsrc;
        fsrc.open(srcFile, ios::binary | ios::in);
        // %% read the content from source file into file_content and calculate size (bytes)
        fsrc.close();
    }
    
    if (entry.entry.size < 0) return 1;
    
    // find sectors to write in
    int sectorsNeeded = (entry.entry.size - 1) / sectorSize_k + 1;
    vector<int> sectorsFree = findEmptySectors(sectorsNeeded);
    
    // %% check if vector returned is empty
    bool enoughSectors;
    if (!enoughSectors) {
        cout << "ERROR: Not enough memory!" << endl;
        return 1;
    }
    
    // %% fill details of file entry (parent, file type)
    // parent is sector corresponding to (current) root directory
    entry.entry.startsAt = sectorsFree[0];
    
    writeEntry(offset, entry.str);
    
    char buf[sectorSize_k];
    // write data and update sector status
    for (int i = 0; i < sectorsNeeded; ++i) {
        for (int j = 0; j < sectorSize_k; ++j) {
            buf[j] = file_content[sectorSize_k*i + j];
        }
        writeSector(sectorsFree[i], buf);
        // we use index of next sector as status of sector as a pointer to show continuation,
        //   last sectors gets status 1
        setStatus(sectorsFree[i], (i != sectorsNeeded-1) ? sectorsFree[i+1] : 1);
    }
    // %% display information about the file created
    return 0;
}
