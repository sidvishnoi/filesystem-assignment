#include "filesystem.h"

int main(int argc, char const *argv[])
{
    string diskTitle;
    int diskSizeBytes;

    // get disk title
    if (argc > 1 && argv[1]) {
        diskTitle = argv[1];
    } else {
        cout << "Enter path to disk: ";
        cin >> diskTitle;
    }

    // check if disk doesn't exists or is empty
    //  and if exists, get it's size in bytes

    /* %%
    >> write a code to check whether the disk already exists or not by checking it's size (store size in diskSizeBytes)
    and update the boolean variable
        alreadyExists = true, if file with same name exists
        else false
    */
    // %% logic here
    bool alreadyExists; // %%;

    // get size if not exists
    if (!alreadyExists) {
        int diskSizeMB;
        if (argc > 2) {
            istringstream iss(argv[2]);
            iss >> diskSizeMB;
        } else {
            cout << "Enter disk size in MiB : ";
            cin >> diskSizeMB;
            cin.ignore(32767, '\n');
        }
        diskSizeBytes = 1024*1024*diskSizeMB;
    }

    // initialize disk
    FileSystem disk(diskTitle, diskSizeBytes, alreadyExists);

    cout << "Type `help` to see available commands." << endl;

    int response = handleInput(disk);
    while (response != 1) {
        response = handleInput(disk);
    }
    return 0;
}