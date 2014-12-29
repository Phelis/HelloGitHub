CC = gcc
CFLAGS = -g -Wall

HelloGitHub: md5.o HelloGitHub.o
	$(CC) $(CFLAGS) -o HelloGitHub md5.o HelloGitHub.o

HelloGitHub.o: HelloGitHub.c
	$(CC) $(CFLAGS) -c HelloGitHub.c

md5.o: md5.h
	$(CC) $(CFLAGS) -c md5.c 

all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f HelloGitHub
	rm -f HelloGitHub.o
	rm -f md5.o
