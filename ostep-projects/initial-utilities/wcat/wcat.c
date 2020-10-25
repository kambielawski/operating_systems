#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: ./wcat <filepath>");
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  char *buffer;
  
  while (buffer = fgets(buffer, 1000, fp)) {
    printf("%s", buffer);
  }

  fclose(fp);

  return 0;
}
