#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("Hello, world! (pid: %d)\n", getpid());

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "failed to foRk");
    exit(1);
  } else if (rc == 0) {
    printf("I am the child! (pid: %d)\n\n", getpid());
    char *args[2];
    args[0] = strdup("./fork");
    args[1] = NULL;
    execvp(args[0], args);
    printf("won't print");
  } else {
    int rc_wait = wait(NULL);
    printf("\nI am the parent of %d (pid: %d)\n", rc_wait, getpid());
  }
  return 0;
}
