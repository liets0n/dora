#include <stdio.h>

void help(const char *program) {
  printf("Dora - A simple command-line file search tool\n");

  printf("\n");

  printf("Usage:\n");
  printf("\t%s [OPTIONS] <filename>\n", program);

  printf("\n");

  printf("DESCRIPTION:\n");
  printf("\tSearch for files on your local machine.\n");

  printf("\n");

  printf("OPTIONS:\n");
  printf("\t-h, --help \t Display this help message\n");

  printf("\n");

  printf("EXAMPLES:\n");
  printf("\t%s document.pdf\n", program);
  printf("\t%s report.txt\n", program);
  printf("\t%s --help\n", program);

  printf("\n");

  printf("For more information, visit:\n");
  printf("https://github.com/liets0n/dora\n");
}
