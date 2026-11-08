#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int find_matches(char *path, char *filename) {
  DIR *dir = opendir(path);

  if (dir == NULL) {
    perror(path);
    return EXIT_FAILURE;
  }

  struct dirent *entry;
  int result = EXIT_SUCCESS;

  while (1) {
    errno = 0;
    entry = readdir(dir);

    if (entry == NULL) {
      if (errno != 0) {
        perror(path);
        result = EXIT_FAILURE;
      }
      break;
    }

    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    size_t size = strlen(path) + strlen(entry->d_name) + 2;
    char *fullpath = malloc(size);

    if (fullpath == NULL) {
      perror("malloc");
      result = EXIT_FAILURE;
      break;
    }

    snprintf(fullpath, size, "%s/%s", path, entry->d_name);

    struct stat info;

    if (lstat(fullpath, &info) == -1) {
      perror(fullpath);
      free(fullpath);
      result = EXIT_FAILURE;
      continue;
    }

    if (strcmp(entry->d_name, filename) == 0)
      printf("%s\n", fullpath);

    if (S_ISDIR(info.st_mode)) {
      if (find_matches(fullpath, filename) != 0)
        result = EXIT_FAILURE;
    }

    free(fullpath);
  }

  closedir(dir);

  return result;
}
