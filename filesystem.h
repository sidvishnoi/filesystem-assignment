#ifndef FILESYSTEM
#define FILESYSTEM

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;


// int to char[4] typecast
typedef struct {
    union {
        int num;
        char str[4];
    };
} TypeCastInt;

// directory entry
typedef struct {
    int  startsAt;
    int  size;
    char type;    // f/d/F/D
    int  parent;
    char name[19];
} dirEntry;

typedef struct {
    union {
        dirEntry entry;
        char str[32];
    };
} TypeCastEntry;


// global variable for file system's sector size
const int kSectorSize_g = 512;

// FileSystem class
class FileSystem {
 private:
    string diskTitle_k;
    int sectorSize_k = kSectorSize_g;
    int diskSize_k;
    int reservedSectors_k;
    int numberOfSectors_k;
    const int sectorsForDir_k = 2;

    // reserves space for disk, called by constructor
    void createDisk();

    // returns a list of available sectors
    vector<int> findEmptySectors(int requiredNumber);

    // check whether entry with same name and exists in current dir
    bool alreadyExists(char *name, char type);

    // return the offsets for free position for file/directory entry
    vector<int> getEntryPosition();

    // write a file/dir entry to Disk
    void writeEntry(vector<int> offset, const char * buffer);

 public:
    // constructor
    FileSystem(string title = "Disk.bin");

    enum Status {FREE = 0, BUSY, RESERVED, NOT_FOUND, DIR_ENTRY, DELETED, END};
    const vector<string> statusMsg {
        "FREE", "BUSY", "RESERVED", "NOT_FOUND", "DIR_ENTRY", "DELETED", "END"
    };

    // read a sector into buf
    int readSector(int sector_no, char *buf);
    // write a sector with content from buf
    int writeSector(int sector_no, char *buf);

    // formats the disk
    void format();

    // get status of a sector
    int getStatus(int sector_no);
    // update status of a sector
    int setStatus(int sector_no, int x);

    // create a new file
    int createFile(const char *title, const char *srcFile);
    // read a file
    int readFile(const char *title);
    // delete a file
    int deleteFile(const char *title);
    // recover a deleted file
    int undeleteFile(const char *title);

    // create a directory
    int createDir(const char *title);
    // change current working directory
    int changeDir(const char *title);

    // change current working directory
    void printWorkingDir();
    // list contents of current working directory
    void listDirectoryContents();
    // display the hierarchy of filesystem
    void tree(int level = 1, int spacing = 2);

    // display information about the file system
    void info();
};

vector<string> split(const string &s, const char delim);
void createBuffer(char temp, char* buf);
int handleInput(FileSystem &disk);

#endif
