#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "./../include/utils.h"

int find_matches(char *path, char *name, size_t *found_count, char *type, char *extension, short ignore_case) {
  DIR *dir = opendir(path);

  if (dir == NULL) {
    perror(path);
    return -1;
  }

  struct dirent *entry;
  int result = 0;

  while (1) {
    errno = 0;
    entry = readdir(dir);

    if (entry == NULL) {
      if (errno != 0) {
        perror(path);
        result = -1;
      }
      break;
    }

    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    size_t size = strlen(path) + strlen(entry->d_name) + 2;
    char *fullpath = malloc(size);

    if (fullpath == NULL) {
      perror("malloc");
      result = -1;
      break;
    }

    snprintf(fullpath, size, "%s/%s", path, entry->d_name);

    struct stat info;

    if (lstat(fullpath, &info) == -1) {
      perror(fullpath);
      free(fullpath);
      result = -1;
      continue;
    }

    int type_matches = 1;

    if (type != NULL) {
      if (strcmp(type, "f") == 0) {
        type_matches = S_ISREG(info.st_mode);
      } else if (strcmp(type, "d") == 0) {
        type_matches = S_ISDIR(info.st_mode);
      }
    }

    char *tmp = malloc(strlen(entry->d_name) + 1);

    if (tmp == NULL) {
      perror("malloc");
      return -1;
    }

    strcpy(tmp, entry->d_name);

    to_lowercase(tmp, ignore_case);

    if (type_matches && (name == NULL || strcmp(tmp, name) == 0)) {
      if (verify_extension(entry->d_name, extension) == 1) {
        printf("%s\n", fullpath);
        (*found_count)++;
      }
    }

    free(tmp);

    if (S_ISDIR(info.st_mode)) {
      if (find_matches(fullpath, name, found_count, type, extension, ignore_case) != 0)
        result = -1;
    }

    free(fullpath);
  }

  closedir(dir);

  return result;
}
