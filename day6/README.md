# Day 6

This is the last day for this assignment. Today we add some methods corresponding to Unix commands like `ls`, `pwd` and other useful commands `tree` and `info`. All these methods do not cause any change in FileSystem, but just provide info about FileSystem to user.

We will not be giving any code or much documentations for these methods but these are easy functions.

### Tasks

Edit `day6/listDirectoryContents.cpp`. This function should print all the names (and/or sizes) of all files and directories in the current working directory.

Edit `day6/tree.cpp`. This is an extension of `ls -R` command. It prints the hierarchical tree of all files and sub-directories inside a directory, recursively, showing a tree like structure. Try to make it beautiful (I know you will!)

Edit `day6/printWorkingDir.cpp`. This is easiest task for day 6. I won't help (PS: you need to use `PATH_NAME`).

Edit `day6/info.cpp`. This will print information about the FileSystem, like number of sectorsm size of each sector, sectors free and so on.


### What's Next?

Now that you have learned some nice concepts of FileSystem, file handling in C++, you're free to go or create something more awesome!

This FileSystem can be used as a base for a low-performace database.

You can use the disk created as an *encrypted* means of sharing your files. Not everyone can easily read binary files! (maybe unless they have also learned and created same FileSystem)

You are encouraged to create more methods like `copyFile`, `moveFile` (like copy somewhere and delete from original position), create a recycle a bin (another directory) and move deleted files there.

Good luck!
