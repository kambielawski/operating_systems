#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ARGS 10

char **getArgs(char *input, char delim, int size) {
  char *word = strtok(input, " ");
  char **ret = NULL;
  int wordCounter = 0;
  while(word) {
    ret = realloc(ret, sizeof(char*) * ++wordCounter);

    if (ret == NULL) {
      printf("memory allocation failed\n");
      exit(1);
    }

    ret[wordCounter-1] = word;

    word = strtok(NULL, " ");
  }
  ret = realloc(ret, sizeof(char*) * (wordCounter+1));
  ret[wordCounter] = NULL;
  return ret;
}

int main(int argc, char *argv[]) {
  
  char *input;
  size_t inputsize = 100;
  size_t characters;

  input = (char *) malloc(inputsize); 

  
  printf("Kam's Shell > ");
  characters = getline(&input, &inputsize, stdin);
  input[characters-1] = '\0';
  characters--;

  char **inputToWords = getArgs(input, '\x20', characters);
  
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "failed to fork");
    exit(1);
  } else if (rc == 0) {
    execvp(inputToWords[0], inputToWords);
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
