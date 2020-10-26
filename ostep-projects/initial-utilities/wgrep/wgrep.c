#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: ./wgrep <filename> <search word>");
    exit(1);
  }
}
