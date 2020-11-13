#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int *arr;

  for (int i = 0; i < 100; i++)
    arr[i] = i;
  
  int *somenum;
  somenum = &arr[10];

  free(somenum);

  arr[100] = 0;

  return 0;
}
