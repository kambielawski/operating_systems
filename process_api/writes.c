#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen("stuff.txt", "w");
  if (fp == NULL) {
    printf("failed to open da file");
    exit(1);
  }

  int rc = fork();
  if (rc < 0) {
    printf("failed to fork da fork\n");
    exit(1);
  } else if (rc == 0) {
    char *childtext = "cccccccccc";
    fwrite(childtext, 1, 10, fp);    
  } else {
    char *parenttext = "pppppppppp";
    fwrite(parenttext, 1, 10, fp);
  }

  return 0;
}