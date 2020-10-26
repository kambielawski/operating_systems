#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFER_SIZE 500

int main(int argc, char *argv[]) {
  if (argc < 2) {
    if (argc == 1) {
      exit(0);
    } else {
      fprintf(stderr, "Usage: ./wcat <filepath>");
      exit(1);
    }
  }

  FILE *fp;
  char *buffer = (char *) malloc(BUFFER_SIZE);

  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    while (fgets(buffer, BUFFER_SIZE, fp)) {
      printf("%s", buffer);
    }
    fclose(fp);
  }

  free(buffer);
  return 0;
}
