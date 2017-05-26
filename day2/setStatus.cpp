#include "../filesystem.h"

int FileSystem::setStatus(int sector_no, int x) {
    /*
    objective: to update status of a given sector
    input:
        sector_no = sector number
        x = status (0 = FREE, 1 = BUSY, other: continuation sector number)
    return:
        (failure) -1
        (success) 0
    effect: a sector is marked in disk
    */

    if (sector_no > numberOfSectors_k - 1) {
        cout << "ERROR: Sector does not exist." << endl;
        return -1;
    }
    if (sector_no < reservedSectors_k) {
        cout << "ERROR: Sector is reserved." << endl;
        return -1;
    }

    // cast will convert an int <x> to a char[4] array, using type-punning
    TypeCastInt cast;
    cast.num = x;

    /* %%
    Compute which to sector update, as minimum unit of read/write is a sector
    >> based on sector_no, computer a <sectorOffset> which should have the status for sector_no
    >> also, compute a <byteOffset> which shows starting from which byte in <sectorOffset>, next 4 bytes need to be updated
    */
    int sectorOffset, byteOffset;
    // compute here

    char buffer[sectorSize_k];
    readSector(sectorOffset, buffer);

    // edit buffer
    for (int i = byteOffset, j = 0; j < 4; ++i, ++j) {
        buffer[i] = cast.str[j];
    }

    writeSector(sectorOffset, buffer);

    return 0;

}
