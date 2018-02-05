#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define FILE_NAME "pic.ppm" //defining the name of the picture file as FILE_NAME

//makes the image
int make_pic (int fd) {
  int i, j;
  char str[5];
  //first color based on x-coord, second color based on y-coord, third color = 0
  for (i = 0; i < 500; i++) {
    for (j = 0; j < 500; j++) {
      sprintf(str, "", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " ", sizeof(" "));
      sprintf(str, "", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " 0\n", sizeof(" 0\n"));
    }
  }
  return 0;
}
int main() {
  //create file
  if (fork() == 0) {
    execlp("touch", "touch", FILE_NAME, NULL);
  }
  //open file
  int fd = open(FILE_NAME, O_WRONLY, 0666);
  //writing in header
  write (fd, "P3\n500 500\n255\n", sizeof("P3\n500 500\n255\n"));
  //make_pic(fd);
    int i, j;
  char str[10];
  //first color based on x-coord, second color based on y-coord, third color = 0
  for (i = 0; i < 500; i++) {
    for (j = 0; j < 500; j++) {
      sprintf(str, "", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " ", sizeof(" "));
      sprintf(str, "", i % 256);
      write (fd, str, sizeof(str));
      write (fd, " 0\n", sizeof(" 0\n"));
    }
  }
}
