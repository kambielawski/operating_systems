#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int pid = (int)getpid();
  // if called from command line, we need the pid
  char strpid[10];
  if (argc < 2) sprintf(strpid, "%d", pid);
  
  // if called from execvp(), we need to check if we're done creating more processes
  if (argc >= 2) {
    int daddy_pid = (int)atoi(argv[1]);
    bool done = daddy_pid + 3 <= getpid();
    if (done) {
      return 0;
    }
  }
  
  printf("Jello,  PID == %d\n", pid);

  int rc = fork();
  if (rc < 0) {
    printf("somehow failed to fork!\n");
    exit(1);
  } else if (rc == 0) {
    int pid = (int)getpid();
    printf("I am a child (pid: %d)\n", pid);
    char *argz[3];
    argz[0] = strdup("./spawn");
    argz[1] = argc == 2 ? argv[1] : strpid;
    argz[2] = NULL;
    execvp(argz[0], argz);
  } else {
    int rc_wait = wait(NULL);
    printf("I (pid %d) am done with my child (pid %d)\n", pid, rc_wait);
  }

  return 0;
}
