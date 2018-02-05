#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define FILE_NAME "pic.ppm" //defining the name of the picture file as FILE_NAME

//makes the image
int make_pic (int fd) {
  int i, j;
  char str[10];
  //first color based on x-coord, second color based on y-coord, third color = 255
  for (i = 0; i < 500; i++) {
    for (j = 0; j < 500; j++) {
      sprintf(str, "%d", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " ", sizeof(" "));
      sprintf(str, "%d", j % 256);
      write (fd, str, sizeof(str));
      write (fd, " 255\n", sizeof(" 255\n"));
    }
  }
  return 0;
}
int main() {
  pid_t child_pid;
  //create file
  if (child_pid = fork() == 0) {
    execlp("touch", "touch", FILE_NAME, NULL);
  }
  //open file
  wait(child_pid);
  int fd = open(FILE_NAME, O_WRONLY, 0666);
  //writing in header
  write (fd, "P3\n500 500\n255\n", sizeof("P3\n500 500\n255\n"));
  make_pic(fd);
    int i, j;
  char str[3];
  //first color based on x-coord, second color based on y-coord, third color = 0
  /* for (i = 0; i < 500; i++) {
    for (j = 0; j < 500; j++) {
      sprintf(str, "", i % 256);
      printf("%s", str);
      write (fd, str, sizeof(str));
      write (fd, " ", sizeof(" "));
      sprintf(str, "", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " 0\n", sizeof(" 0\n"));
      }
    }*/
}
