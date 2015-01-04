CC := gcc
CFLAGS := -g -Wall -Werror
LOCAL_SRC_FILES := libs

HelloGitHub: md5.o crc32.o allocator.o HelloGitHub.o
	$(CC) $(CFLAGS) -o HelloGitHub libs/crc32.o libs/md5.o libs/allocator.o HelloGitHub.o

HelloGitHub.o: HelloGitHub.c
	$(CC) $(CFLAGS) -c HelloGitHub.c

# include makefiles
include config.mk
include libs/Makefile

all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f HelloGitHub
	rm -f HelloGitHub.o
	rm -f $(wildcard libs/*.o)
