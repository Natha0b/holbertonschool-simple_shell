#include "shell.h"

/**
 * file_exist - function check the file
 * @filename: variable char
 * Return: int
*/

int file_exists(char *filename)
{
  int fd=open(filename, O_RDONLY);
  if (fd==-1)
    {
      if (errno==2)
        return 0;
      else
        return -1;
    }
  close(fd);
  return 1;
}
