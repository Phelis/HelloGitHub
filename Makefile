CC = gcc

HelloGitHub: HelloGitHub.c
	$(CC) HelloGitHub.c -o $@ -Wall -Werror

all:
	HelloGitHub

.PHONY: clean
clean:
	rm -f HelloGitHub
