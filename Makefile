CC = gcc
CFLAGS = -g -Wall

HelloGitHub: md5.o HelloGitHub.o
	$(CC) $(CFLAGS) -o HelloGitHub libs/md5.o HelloGitHub.o

HelloGitHub.o: HelloGitHub.c
	$(CC) $(CFLAGS) -c HelloGitHub.c

md5.o: libs/md5.h
	$(CC) $(CFLAGS) -o libs/md5.o -c libs/md5.c

all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f HelloGitHub
	rm -f HelloGitHub.o
	rm -f libs/md5.o
