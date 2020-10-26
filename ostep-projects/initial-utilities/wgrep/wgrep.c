#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

void check_for_word(char *buffer, char *word) {
  if (strstr(buffer, word)) {
    printf("%s", buffer);
  }
}

int main(int argc, char *argv[]) {

  FILE *fp;
  char *buffer = (char *)malloc(BUFFER_SIZE);

  if (argc < 3) {
    if (argc == 1) {
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
    } else if (argc == 2) {
      char *word = argv[1];
      while (fgets(buffer, BUFFER_SIZE, stdin)) {
        check_for_word(buffer, word);
      }
      return 0;
    } else {
      exit(0);
    }
  }
  
  char *word = argv[1];

  // for each file
  for (int i = 2; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    
    while (fgets(buffer, BUFFER_SIZE, fp)) {
      check_for_word(buffer, word);
    }
    
    fclose(fp);
  }

  return 0;
}
