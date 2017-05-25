#include "../filesystem.h"

// constructor
FileSystem::FileSystem(
    string title = "Disk.bin", // default title for disk
        int diskSize = 1024*1024, // 1Mib = 1024*1024 bytes (default)
        bool alreadyExists = false) :
        diskTitle_k(title),
        diskSize_k(diskSize) {

}