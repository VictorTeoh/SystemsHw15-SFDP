#include "headers.h"

int main(){


}


int create(int N){
  int mem = shmget(mKEY , sizeof(int), IPC_EXCL | IPC_CREAT | 0600 );
  int sem = semget(sKEY, 1, IPC_EXCL | IPC_CREAT | 0600);
  open("story", O_CREAT | O_EXCL | O_TRUNC, 0600);
  semctl(sem,0,SETVAL, N);
  printf("Semaphore hast been made: %d\n", sem);
  return sem;
}

void view(){
  int size = stat( "story", st_size );
  char buff[size];
  int fd = open("story", O_RDONLY, 0600);
  read(fd , buff , size );
}

int remove(){
  int sem = semget(sKEY, 1, 0600);
  semctl(sem, 0, IPC_RMID);
  if(sem == -1){
    printf("Nothin to del, boss!\n");
    return 0;
  }
  printf("Deleted sem: %d\n",sem);
  return sem;
}
