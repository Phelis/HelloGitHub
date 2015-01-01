CC = gcc
CFLAGS = -g -Wall -std=c11

HelloGitHub: md5.o allocator.o HelloGitHub.o
	$(CC) $(CFLAGS) -o HelloGitHub libs/md5.o libs/allocator.o HelloGitHub.o

HelloGitHub.o: HelloGitHub.c
	$(CC) $(CFLAGS) -c HelloGitHub.c

md5.o: libs/md5.h
	$(CC) $(CFLAGS) -o libs/md5.o -c libs/md5.c

allocator.o: libs/allocator.h
	$(CC) $(CFLAGS) -o libs/allocator.o -c libs/allocator.c
all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f HelloGitHub
	rm -f HelloGitHub.o
	rm -f libs/md5.o
