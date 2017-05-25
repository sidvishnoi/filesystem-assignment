#include "../filesystem.h"

int FileSystem::writeSector(int sector_no, char *buf)
{
    /*
    objective: to write a sector in disk
    input:
        sector_no: sector number to write in
        buf: a buffer of size sectorSize_k bytes, which is to be written in the sector
    return:
        0: success
        1: failure (%% handle errors)
    */

    ofstream fp;
    // open disk file in edit mode
    fp.open(diskTitle_k, ios::binary | ios::in | ios::out);

    /* %%
    at which byte position the buf be written?
    >> put that expression by replacing -1 below
    */
    int byteOffset = -1;
    fp.seekp(byteOffset);

    fp.write(buf, sectorSize_k);
    fp.close();

    return 0;
}