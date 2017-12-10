#include "headers.h"

int main(){


}


void get_line(int fd, int size){
  lseek(fd, -size, SEEK_END);
  char line[size];
  read(fd, line, size);
  printf("%s\n", line);
}

void write_line(int fd, char * line){
  lseek(fd, 0, SEEK_END);
  write(fd, line, strlen(line));
}
