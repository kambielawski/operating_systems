#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf;
  int pipefd[2];

  if (argc < 2) {
    printf("usage: ./pipe <string>");
    exit(1);
  }

  if (pipe(pipefd) < 0) {
    printf("pipe failed!");
    exit(1);
  }

  int rc = fork();

  if (rc < 0) {
    printf("fork failed!");
    exit(1);
  } else if (rc == 0) {
    close(pipefd[1]);
    while (read(pipefd[0], &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);

    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    exit(0);
  } else {
    close(pipefd[0]);
    write(pipefd[1], argv[1], strlen(argv[1]));
    close(pipefd[1]);
    exit(0);
  }
  return 0;
}
