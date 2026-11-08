#include <ctype.h>
#include <string.h>

void to_lowercase(char *letter, short ignore_case) {
  if (ignore_case == 0)
    return;

  for (int i = 0; letter[i] != '\0'; i++) {
    letter[i] = (char)tolower((unsigned char)letter[i]);
  }
}

int verify_extension(const char *filename, const char *extension) {
  if (extension == NULL)
    return 1;

  const char *dot = strrchr(filename, '.');

  if (dot == NULL || dot == filename || dot[1] == '\0') {
    return 0;
  }

  if (*extension == '.') {
    extension++;
  }

  return strcmp(dot + 1, extension) == 0;
}
