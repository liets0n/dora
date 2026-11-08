#include <stdio.h>

void help(const char *program) {
  printf("Dora - A simple command-line file search tool\n");

  printf("\n");

  printf("Usage:\n");
  printf("\t%s [OPTIONS] -d <directory> -n <name>\n", program);

  printf("\n");

  printf("DESCRIPTION:\n");
  printf("\tSearch for files on your local machine.\n");

  printf("\n");

  printf("OPTIONS:\n");
  printf("\t-h, --help\n");
  printf("\t\t Display this help message\n");

  printf("\n");

  printf("\t-d, --directory <directory>\n");
  printf("\t\t Specify the directory where the search will start\n");

  printf("\n");

  printf("\t-n, --name <name>\n");
  printf("\t\t Search for a file or directory by name\n");

  printf("\n");

  printf("\t-t, --type <file_type>\n");
  printf("\t\t Filter by entry type (f=file, d=directory)\n");

  printf("\n");

  printf("\t-e, --extension <extension>\n");
  printf("\t\t Filter files by extension (e.g. pdf, txt))\n");

  printf("\n");

  printf("EXAMPLES:\n");
  printf("\t%s -d .\n", program);
  printf("\t%s -d Downloads -n document.pdf\n", program);

  printf("\n");

  printf("For more information, visit:\n");
  printf("https://github.com/liets0n/dora\n");
}
