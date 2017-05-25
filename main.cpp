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

    // initialize disk
    FileSystem disk(diskTitle);

    cout << "Type `help` to see available commands." << endl;

    int response = handleInput(disk);
    while (response != 1) {
        response = handleInput(disk);
    }
    return 0;
}