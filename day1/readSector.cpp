#include "../filesystem.h"

int FileSystem::readSector(int sector_no, char *buf)
{
    /*
    objective: to read a sector from disk into buf
    input:
        sector_no: sector number to read
        buf: a buffer of size sectorSize_k bytes, into which the content of sector are to be read
    return:
        0: success
        1: failure (%% handle errors)
    */
    ifstream fin;
    fin.open(diskTitle_k, ios::binary | ios::in);

    /* %%
    at which byte position the buf be read from?
    >> put that expression by replacing -1 below
    (hint: same as in writeSector())
    */
    int byteOffset = -1;
    fin.seekg(byteOffset);

    fin.read(buf, sectorSize_k);
    fin.close();
    return 0;
}