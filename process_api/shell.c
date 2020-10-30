#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  char *input;
  size_t inputsize = 100;
  size_t characters;

  input = (char *) malloc(inputsize); 
  
  printf("Kam's Shell > ");
  characters = getline(&input, &inputsize, stdin);
  input[characters-1] = '\0';
  characters--;
  
  int rc = fork();
  if (rc < 0) {
    printf("fork failed!!!\n");
    exit(1);
  } else if (rc == 0) {
    execlp(input, input, NULL);
  } else {
    wait(NULL);
    if (!strncmp(input, strdup("quit"), 4)) {
      return 0;
    } else {
      char *nextcall[2];
      nextcall[0] = strdup("./shell");
      nextcall[1] = NULL;
      execvp(nextcall[0], nextcall);
    }
  }
  
  return 0;
}
