# Day 2

Today, we will add another two important basic methods for our FileSystem.

In the file system, we reserved some sectors in the beginning of disk. We will use them for storing the status of remaining sectors. We call a sector `FREE` if it's corresponding byte position in the reserved sectors in `0`. A `BUSY` sector is marked by `1`. `1` is also used as an end of continuation for linked sectors. A sector marked by negative integers is used to show them as `DELETED`, means they can be used as `FREE` if there are not enough free sectors available.

### Task 1

You first need to understand at which byte in disk, the status of a (non-reserved) sector is stored. As the smallest unit for a read/write in disk is a sector, you will need to read a sector, update it's some particular bytes in a buffer and then write the updated buffer to it's right place again.

In a disk with sector size `sectorSize_k` and `reservedSectors_k` sectors reserved, let `s` be the first non-reserved sector.

The status of `s` is stored in first 4 bytes of the disk (also in first sector (`S = 0, B = [0, 3]`)). The status of `s+1` is in `S = 0, B[4, 7]` and so on.

Based on this, you need to calculate two offsets for a sector's status: `sectorOffset` (S) and `byteOffset` (B, which tells which byte in a sector S). Create a general expression for this.

### Task 2

Go through the each file: `day2/setStatus.cpp` and `day2/getStatus.cpp`.

Update `day2/setStatus.cpp`. (line 28)

Update `day2/getStatus.cpp` similarly.   

### Task 3

Test.

Test by storing status for various sectors and fetching them. Also, see how the created disk file changes. It is an important method, so make sure you do it right.
