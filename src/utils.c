#include <ctype.h>

void to_lowercase(char *letter, short ignore_case) {
  if (ignore_case == 0)
    return;

  for (int i = 0; letter[i] != '\0'; i++) {
    letter[i] = (char)tolower((unsigned char)letter[i]);
  }
}
