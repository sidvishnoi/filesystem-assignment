# Day 5

Now we start making our file system hierarchical. So we need to add directories.

We make two new methods - `createDir` and `changeDir`. These two methods will also cause so many changes in a lot of codes! But don't worry, it's cool!

### Task 1

In `day1/FileSystem.cpp`, initialize `currentDir` to first non-reserved sector.

In day 3 tasks, you need to start the searching from currentDir, not necessarily the first non-reserved sector. So you need to edit `day3/alreadyExists.cpp` and `day3/getEntryPosition.cpp` also. This is the benefit of creating separate modules for such functions. You don't need to edit (and compile) each file which uses those functions and edits are localized.

### Task 2

Edit `day5/createDir.cpp`.  We reserve `sectorsForDir_k` sectors for a new directory and create it's entry in current directory.

### Task 3

Edit `day5/changeDir.cpp`.  We've already added two types of directory changes. You should be able to figure out the edits required.

`PATH_ID` stores the sector numbers in current path (intially empty) and `PATH_NAME` stores the names of directories you're in. It pushes both sector numbers and names into path variables. `PATH_NAME` will be useful to implement 5th day's `printWorkingDir` method.

### Task 4

Test. Test. Test.

* Create new directories and sub-directories and navigate through them.
* Fix any bugs you find.
* Create files in sub-directories also.
* Read the files in sub-directories.
* Try to create files with same names in different directories and try to read each.
