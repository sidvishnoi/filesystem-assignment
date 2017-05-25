#include "filesystem.h"

#ifndef COLORS    // colors for terminal
#define COLORS ""
#define KRST  "\x1B[0m"
#define KGRN "\x1b[32m"
#define KYEL "\x1b[33m"
#define KBLU  "\x1B[34m"
#define DASH u8"\u2015" << u8"\u2015" << " "
#endif

vector<string> split(const string &s, const char delim) {
    /*
    castective: to split a string by given delimitter
    input:
        s: given string
        delim: delimitter
    return: vector of strings split at given delimitter
    */
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

void createBuffer(char temp, char* buf) {
    // creates a buffer based on a char
    if (temp == '.') {
        cout << "Enter alphabet: ";
        cin >> temp;
        cin.ignore(32767, '\n');
    }
    for (int i = 0; i < kSectorSize_g; i++) {
        buf[i] = temp;
    }
}

int handleInput(FileSystem &disk) {
    /*
    objective: to create a terminal like CLI to handle disk operations
    input: reference to disk
    return:
        0: continue
        1: exit
    */
    string command;
    cout << KGRN << "(myFileSystem)> " << KRST;
    getline(cin, command);
    if (command.empty()) return 1;

    // split command into function and argument part
    vector<string> tokens;
    tokens = split(command, ' ');
    string fun = tokens[0];
    string arg = "";
    if (tokens.size() > 1) {
        arg = tokens[1];
    }

    string arg2 = "";
    if (tokens.size() > 2) {
        arg2 = tokens[2];
    }

    enum Choice {
        HELP, INFO, TREE, READ, CHECK, WRITE, FORMAT, EXIT, NEW_FILE, CAT, DEL, UNDEL, MKDIR, CD, PWD, LS, END
    };
    string CHOICES[] = {
        "help", "info", "tree", "read", "check", "write", "format", "exit", "new", "cat", "del", "undel", "mkdir", "chdir", "pwd", "list", ""
    };
    string choices[] = {
        "h", "info", "tree", "r", "c", "w", "f", "q", "n", "cat", "del", "undel", "mkdir", "cd", "pwd", "ls", ""
    };

    Choice selected = END;
    for (int i = 0; i < END; ++i) {
        if (CHOICES[i] == fun || choices[i] == fun) {
            selected = static_cast<Choice>(i);
            break;
        }
    }

    int sector;
    // handle command
    switch (selected) {
        case READ: {
            if (arg.empty()) {
                cout << "usage: read SECTOR" << endl;
                return 0;
            }
            // convert string to int
            istringstream(arg) >> sector;
            char readBuffer[kSectorSize_g];
            disk.readSector(sector, readBuffer);
            for (int i = 0; i < kSectorSize_g; ++i) {
                cout << readBuffer[i];
            }
            cout << endl;
            break;
        }
        case WRITE: {
            if (arg.empty()) {
                cout << "usage: write SECTOR" << endl;
                return 0;
            }
            istringstream(arg) >> sector;
            if (disk.getStatus(sector) == FileSystem::BUSY) {
                cout << "Overwrite sector data (y/n)? _\b";
                char t;
                cin >> t;
                if (t == 'y' || t == 'Y') {
                    char buf[kSectorSize_g];
                    createBuffer('.', buf);
                    disk.writeSector(sector, buf);
                } else {
                    cin.ignore(32767, '\n');
                    return 0;
                }
            } else {
                char buf[kSectorSize_g];
                createBuffer('.', buf);
                disk.writeSector(sector, buf);
                disk.setStatus(sector, 1);
            }
            break;
        }
        case CHECK: {
            if (arg.empty()) {
                cout << "usage: check SECTOR" << endl;
                return 0;
            }
            istringstream(arg) >> sector;
            int status = disk.getStatus(sector);
            cout << "sector #" << sector << " is ";
            if (status < disk.END && status > -1) {
                cout << disk.statusMsg[status] << endl;
            } else {
                cout << "pointing to sector #" << status << endl;
            }
            break;
        }
        case FORMAT:
            disk.format();
            break;
        case HELP: {
            ifstream helpFile;
            helpFile.open("help.txt", ios::in | ios::ate);
            int helpFileSize = helpFile.tellg();
            char helpMsg[helpFileSize];
            helpFile.seekg(0);
            helpFile.read(helpMsg, helpFileSize);
            helpFile.close();
            cout << helpMsg << endl;
            break;
        }
        case INFO:
            disk.info();
            break;
        case TREE:
            disk.tree();
            break;
        case NEW_FILE: {
            if (arg.empty()) {
                cout << "usage: new FILE_NAME [SRC_FILE]" << endl;
                return 0;
            }
            disk.createFile(arg.c_str(), arg2.c_str());
            break;
        }
        case CAT: {
            if (arg.empty()) {
                cout << "usage: cat FILE_NAME" << endl;
                return 0;
            }
            disk.readFile(arg.c_str());
            break;
        }
        case DEL: {
            if (arg.empty()) {
                cout << "usage: del FILE_NAME" << endl;
                return 0;
            }
            disk.deleteFile(arg.c_str());
            break;
        }
        case UNDEL: {
            if (arg.empty()) {
                cout << "usage: undel FILE_NAME" << endl;
                return 0;
            }
            disk.undeleteFile(arg.c_str());
            break;
        }
        case MKDIR: {
            if (arg.empty()) {
                cout << "usage: mkdir DIR_NAME" << endl;
                return 0;
            }
            disk.createDir(arg.c_str());
            break;
        }
        case CD: {
            if (arg.empty()) {
                cout << "usage: cd DIR_NAME" << endl;
                return 0;
            }
            vector<string> dir = split(arg, '/');
            for (int i = 0; i < dir.size(); ++i) {
                disk.changeDir(dir[i].c_str());
            }
            break;
        }
        case PWD:
            disk.printWorkingDir();
            break;
        case LS:
            disk.listDirectoryContents();
            break;
        case EXIT:
            return 1;
        default:
            cout << "(myFileSystem): command not found: " << fun << endl;
            return 0;
    }
    return 0;
}