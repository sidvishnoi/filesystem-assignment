OBJ = main.o handleInput.o day1/FileSystem.o day1/createDisk.o day1/writeSector.o day1/readSector.o day2/getStatus.o day2/setStatus.o day2/format.o day3/findEmptySectors.o day3/alreadyExists.o day3/getEntryPosition.o day3/writeEntry.o day3/createFile.o day3/readFile.o day4/deleteFile.o day4/undeleteFile.o day5/createDir.o day5/changeDir.o day6/printWorkingDir.o day6/listDirectoryContents.o day6/info.o day6/tree.o

DEP = filesystem.h
CC  = g++
CFLAGS = -std=c++11

all: $(OBJ) $(DEP)
	$(CC) $(CFLAGS) -o filesystem $(OBJ)

%.o: %.cpp $(DEP)
	g++ $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@rm -f *.gch
	@rm -f *.bin
	@rm filesystem
