#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char **argv) {
  printf("process %d\n", getpid());
  if (argc < 2) {
    fprintf(stderr, "usage: ./memoryuser <number of KB to use>");
    exit(1);
  }
  
  printf("%s kb being used on process w/ pid=%d", argv[1], getpid());
  int numKb = atoi(argv[1]);
  int numEntries = numKb * 1000;
  void *arr = malloc(numEntries);

  while (1) {
    memset(arr, 0, numEntries);
  }
  
  return 0;
}
