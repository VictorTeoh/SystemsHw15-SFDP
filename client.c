#include "headers.h"

int main(){
  printf("Please wait patiently for another process to finish\n");
  struct sembuf semb;
  semb.sem_op = -1;
  semb.sem_num = 0;
  semb.sem_flg = SEM_UNDO;
  int sem = semget(sKEY, 1, 0);
  semop(sem, &semb, 1);

  int fd = open("story", O_APPEND | O_RDWR);
  int shm = shmget(mKEY, sizeof(int), 0);
  int *size = shmat(shm, 0, 0);
  printf("%d\n", *size);
  
  get_line(fd, *size);
  
  char line[256];
  fgets(line, sizeof(line), stdin);
  
  write_line(fd, line);

  *size = strlen(line);
  //semop(sem, &semb, 1);
  return 0;
}


void get_line(int fd, int size){
  lseek(fd, -1 * size, SEEK_END);
  char line[size];
  read(fd, line, size);
  printf("Story :\n%s\n", line);
}

void write_line(int fd, char * line){ 
  lseek(fd, 0, SEEK_END);
  write(fd, line, strlen(line));
}
