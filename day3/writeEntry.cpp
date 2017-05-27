#include "../filesystem.h"
    
    void FileSystem::writeEntry(vector<int> offset, const char * buffer) {
        /*
         Objective: to write a file/dir entry at right offset
         Input Parameters:
            offset (sectorOffset, byteOffset) to write at
            buffer: 32 bytes from cast.str
         return: None
         effect: 32 bytes of new entry are written in disk
         */
        char buf[sectorSize_k];
        readSector(offset[0],buf);
        
        // %% modify correct 32 bytes of 'buf' starting from byte offset
        
        // write updated buf
        writeSector(offset[0], buf)
    }

}
