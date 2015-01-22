TEST :=
CC := gcc
JAVA := javac
CFLAGS := -g -Wall -Werror
LOCAL_SRC_FILES := libs

HelloGitHub: HelloJava.class md5.o crc32.o allocator.o Resources.o HelloGitHub.o
	@$(CC) $(CFLAGS) -o HelloGitHub libs/crc32.o libs/md5.o \
			libs/allocator.o Resources.o HelloGitHub.o

HelloGitHub.o: HelloGitHub.c
	@$(CC) $(CFLAGS) -c HelloGitHub.c

Resources.o: Resources.h
	@$(CC) $(CFLAGS) -c Resources.c

# pipe error messages to /dev/null and prefixing with '@' to silence
# 2 is the file descriptor for standard error
# > is for redirect
# & is the symbol for file descriptor
HelloJava.class: HelloJava.java
	@$(JAVA) HelloJava.java > /dev/null 2>&1

# include makefiles
include config.mk
include libs/Makefile


all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f $(wildcard *.o)
	rm -f $(wildcard libs/*.o)
