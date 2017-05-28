# Day 3

Today we add a much more pracically useful method to our file system - the ability to create files.

### Task 1

Go through `day3/createFile.cpp`. You can see we've made put up a lot for you to work on this time. To make the main methods easier, we'll be creating some helper functions as following.

### Task 2

Edit `day3/alreadyExists.cpp`. We look in the current directory (the root directory) for file entries. If we find a file entry with same name and type (`f`), already existing in the current directory, we cannot create another file with same name. So you need to add some comparison for the loop's return condition (line 22).

### Task 3

Go through `day3/getEntryPosition.cpp`. This helper method will return the offsets for a free position where we can put our 32-byte directory/file entry. This will also tell if there is enough space for file entry in current directory or not.

### Task 4

Go through `day3/findEmptySectors.cpp` (you'll need to edit this on day 4). This helper method will return a list (`vector<int>`) of the sectors where we can put the chunks of our file in. It looks for sectors that are `FREE` and adds them to the list. If enough sectors cannot be found (lack of space in disk), it returns and empty list.

### Task 5

Edit `day3/writeEntry.cpp`. this helper method will help you in writing/updating a file/directory entry at it's right place. Based on offsets (sector, byte) where we have free space for file entry, we have to update the required 32-bytes of the buffer and write the updated buffer at right place.

### Task 6

This is the main task you need to do today. Edit `day3/createFile.cpp`.

There are multiple edits required in this public method. Go through each. We have added comments for your help there.

### Task 7

As you've created files, you need to add ability to read them. Edit `day3/readFile.cpp`. It is somewhat opposite of what you did in `createFile` but it is much easier.

### Task 8

Test.

Create multiple files using command

```
(myFileSystem)> new NEW_FILE [SRC_FILE]
(myFileSystem)> cat NEW_FILE
```

SRC_FILE is some file in your computer. you can enter absolute/related path to that. it is used only for convenience to avoid typing large chunks of data

Try to see what happens when you create too much files or create very large files.
