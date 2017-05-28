#include "../filesystem.h"

int FileSystem::changeDir(const char *title) {
    /*
     objective: to change the current working directory
     input: (title) directory to change to
     return:
        0: success
        1: fail (child directory does not exist in current directory)
     effect: the currentDir and current path (PATH_ID and PATH_NAME) are updated
     */
    
    if (!strcmp(title, "..")) {
        if (!PATH_ID.empty()) {
            currentDir = PATH_ID.back();
            PATH_NAME.pop_back();
            PATH_ID.pop_back();
            return 0;
        }
        return 1;
    }
    
    if (!strcmp(title, "/")) {
        currentDir = reservedSectors_k;
        PATH_ID.clear();
        PATH_NAME.clear();
        return 0;
    }
    
    vector<int> offset; // %% value returned by alreadyExists()
    
    // %% use alreadyExists() to check if given dir. exists
    bool dirExists;
    if (!dirExists) {
        // %% print error message
        return 1;
    }
    
    PATH_ID.push_back(currentDir);
    PATH_NAME.push_back(entry.entry.name);
    currentDir = entry.entry.startsAt;
    
    return 0;
}
