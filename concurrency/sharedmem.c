#include <stdio.h>
#include <assert.h>
#include <pthread.h>

static volatile int counter = 0;

void *threadfunc (void *arg) {
  for (int i = 0; i < 1e7; i++) {
    counter++;
  }
  printf("%s: done\n", (char *) arg);
  return NULL;
}


int main (int argc, char *argv[]) {
  pthread_t p1, p2;
  int rc;

  rc = pthread_create(&p1, NULL, threadfunc, "A"); assert(rc == 0);
  rc = pthread_create(&p2, NULL, threadfunc, "B"); assert(rc == 0);

  rc = pthread_join(p1, NULL); assert(rc == 0);
  rc = pthread_join(p2, NULL); assert(rc == 0);

  printf("done with both: counter == %d\n", counter);

  return 0;
}
