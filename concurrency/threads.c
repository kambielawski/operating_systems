#include <pthread.h>
#include <stdio.h>
#include <assert.h>

void *threadfunc(void *arg) {
  printf("%s\n", (char *) arg);
  return NULL;
}

int main (int argc, char *argv[]) {
  pthread_t p1, p2;
  int rc;

  printf("main: begin\n");
  // create the threads
  // threads may begin execution as soon as they are created
  rc = pthread_create(&p1, NULL, threadfunc, "A"); assert(rc == 0);
  rc = pthread_create(&p2, NULL, threadfunc, "B"); assert(rc == 0);

  // pthread_join will wait until execution is finished
  rc = pthread_join(p1, NULL); assert(rc == 0);
  rc = pthread_join(p2, NULL); assert(rc == 0);

  printf("main: end\n");

  return 0;
}
