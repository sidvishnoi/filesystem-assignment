# Day 1

Today, you'll create two base level API methods for the FileSystem and also reserve space for the disk.

### Task 0

Go through the `filesystem.h` file.

### Task 1

**Update the constructor** `day1/FileSystem.cpp`

*  EDIT 1 (line 10): `alreadyExists`, `diskSize_k`
*  EDIT 2 (line 28): `numberOfSectors_k`
*  EDIT 3 (line 34): `reservedSectors_k`

> Hints for edit 2, 3:
>
> Consider a disk of size 1MiB (2^20 bytes) with sector size 512 bytes (2^9). It has total 2^11 sectors. Each sector can store status of 512/4 = 128 (= 2^7) sectors. so for 2^11 sectors, we need to reserve 16 (= 2^4) sectors.
>
> **The factor of 4:** `4 bytes == sizeof(int)`. Edit your code if different on your workstation. We need one integer to store the  *status* of a sector. You might need a long int if you have a lot of sectors.

### Task 2

Go through `day1/createDisk.cpp`. The minimum unit of read or write in a disk is a sector. We'll use this fact throughout the assignment and to make things easier to handle, we make two base level API methods - `readSector` and `writeSector`.

### Task 3

Update `day1/readSector.cpp` and `day1/writeSector.cpp` for `byteOffset` variable. This will tell you which bytes (total `sectorSize_k` bytes at a time) need to be read/written from/to the disk.

*  EDIT: `byteOffset`
*  EDIT: handle errors

### Task 4

Test the work done and debug if needed.

``` bash
$ make
$ ./filesystem
```

```
Enter path to disk: mydisk.bin
Enter disk size in MiB : 1
(myFileSystem)> read 0
(myFileSystem)> read 1
(myFileSystem)> write 0
Enter alphabet: a
(myFileSystem)> read 0
(myFileSystem)> read 1
```

You should test your code for various sectors, as this a very import base method, which will be used throughout the assignment.

Also, handle some errors like if sector_no is negative or doesn't exist in disk, in `day1/readSector.cpp` and `day1/writeSector.cpp`.
