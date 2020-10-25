#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main(int argc, char *argv[]) {
  int *p = malloc(sizeof(int));
  assert(p != NULL);
  printf("(%d) address pointed to by p: %p\n", getpid(), p);
  *p = 0;

  while (1) {
    *p = *p + 1;
    printf("(%d) p: %d\n", getpid(), *p);
    delay(100);
  }
}
