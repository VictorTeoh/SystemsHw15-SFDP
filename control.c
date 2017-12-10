#include "headers.h"

int main(int argc, char ** argv){
  if(argc < 2){
    printf("Not enough args\n");
    exit(0);
  }
  
  if( !strcmp(argv[1], "-c" ) )
    create_all();
  else if( !strcmp(argv[1], "-v") )  
    view_story();
  else if( !strcmp(argv[1], "-r") ) 
    remove_all();
  else
    printf("Invalid arg: %s\n", argv[1]);  
  
  return 0;
}


void create_all(){
  int sem = semget(sKEY, 1, IPC_EXCL | IPC_CREAT | 0600);
  shmget(mKEY , sizeof(int), IPC_EXCL | IPC_CREAT | 0600 ); 
  open("story", O_CREAT | O_RDWR | O_TRUNC, 0644);
  semctl(sem,0,SETVAL, 1);
  printf("Story created!\n");
}

void view_story(){
  struct stat story;
  stat("story", &story);
  int size = story.st_size;
  char buff[size];
  int fd = open("story", O_RDONLY);
  read(fd , buff , size );
  printf("Story:\n%s\n", buff);
}

void remove_all(){
  int sem = semget(sKEY, 1, 0);
  semctl(sem, 0, IPC_RMID);
  printf("Deleted semaphore!\n");
  int shm = shmget(mKEY, sizeof(int), 0);
  shmctl(shm, IPC_RMID, 0);
  printf("Deleted shared memory!\n");
  view_story();
  remove("story");
}
