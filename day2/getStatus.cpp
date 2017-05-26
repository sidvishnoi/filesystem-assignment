#include "../filesystem.h"

int FileSystem::getStatus(int sector_no) {
    /*
    objective: to get status of a given sector
    input:
        sector_no = sector number
    return:
        status of a sector
    */

    if (sector_no > numberOfSectors_k - 1) {
        cout << "ERROR: Sector does not exist." << endl;
        return NOT_FOUND;
    }
      if (sector_no < reservedSectors_k) {
        cout << "ERROR: Sector is reserved." << endl;
        return RESERVED;
    }

    // cast will convert a char[4] array to an int, using type-punning
    TypeCastInt cast;

    /* %%
    Compute which to sector read from, as minimum unit of read/write is a sector
    >> based on sector_no, computer a <sectorOffset> which should have the status for sector_no
    >> also, compute a <byteOffset> which shows starting from which byte in <sectorOffset>, next 4 bytes need to be read
    (hint: same as in setStatus())
    */
    int sectorOffset, byteOffset;
    // compute here

    char buffer[sectorSize_k];
    readSector(sectorOffset, buffer);

    // edit buffer
    for (int i = byteOffset, j = 0; j < 4; ++i, ++j) {
        cast.str[j] = buffer[i];
    }

    return cast.num;

}
