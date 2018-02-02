#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define FILE_NAME "pic.ppm"

//makes the file to store the image
int make_file() {
  return open(FILE_NAME, O_WRONLY, 0600);
}

//creates the image in an inputted file
int create_image(int fd) {
  header(fd);
  pic(fd);
}

//writes the header for the file
int header(int fd) {
  char * buffer = "P3\n500 500\n255\n";
  write(fd, buffer, sizeof(buffer));
  printf("header written");
  return 1;
}

//writes the image for the file
int pic(int fd) {
  int i; int j;
  char * buffer[100];
  for(i = 0; i < 500; i++) {
    for(j = 0; j < 500; j++) {
      buffer = strcat(
}

int main() {
  int fd = make_file();
  create_image(fd);
  printf("Image created!\n");
}
