#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define mKEY 7
#define sKEY 5

void create_all();
void remove_all();
void view_story();

void get_line(int fd, int size);
void write_line(int fd, char * line);
