# Day 4

Today we add another useful ability to our FileSystem. To delete and recover deleted files.

We do not actually delete the files and their content from the disk. We just mark them as deleted, so may be able to recover them later. We mark a file deleted by making is file entry as `F` and marking the sectors it uses as negative of pointers they we pointing before, so we can recover them easily later.

### Task 1

Edit `day4/deleteFile.cpp`. We first check whether the file with same title exists in current directory or not. We then check it's type - `f` (ready to mark as deleted) or `F` (already deleted, deleting again will cause permanent delete).

### Task 2

Edit `day4/undeleteFile.cpp`. We then try to recover a deleted file. We look for file entry with title as given and type as `F`. We can only recover files which are marked deleted.

### Task 3

Edit `day3/findEmptySectors.cpp` to handle sectors which are marked deleted. We may see that we do not have enough free sectors, but there may be some sectors which are marked `DELETED`. We can use them if we need (with lower priority). But once we use those sectors, the corresponding files (marked deleted) will not be accessible. You should see the effects of this and handle it.

### Task 4

Test.

Delete some files which you created in day 3 and try to recover them. Delete some files permanently (by calling delete command on that file again). Create some more files to see if they occupy space that we marked deleted.
