#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
  static const int data = 12;
  static const int bss = 0;
  printf("location of text: %p\n", (void *) main);
  printf("location of data: %p\n", (void *) &data);
  printf("location of bss: %p\n", (void *) &bss);
  int x = 4;
  printf("location of heap: %p\n", (void *) malloc(1));
  printf("location of stack: %p\n", (void *) &x);
  printf("can we do THIS?! : %d\n", *(&x + 0x000000000a00));

  return 0;
}
