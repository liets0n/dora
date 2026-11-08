#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "./../include/dir.h"
#include "./../include/usage.h"

int main(const int argc, char *argv[]) {
  const struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
  };

  int help_requested = 0;
  int option;

  while ((option = getopt_long(argc, argv, ":h", long_options, NULL)) != -1) {
    switch (option) {
      case 'h':
        help_requested = 1;
        break;
      case ':':
        fprintf(stderr,
          "Error: A value is required for '-%c' but none was supplied.\n\n"
          "Try '%s --help' for more information.\n",
          optopt, argv[0]);

        return EXIT_FAILURE;
      case '?':
        fprintf(stderr,
          "Error: Unexpected argument '-%c' found.\n\n"
          "Try '%s --help' for more information.\n",
          optopt, argv[0]);

        return EXIT_FAILURE;
      default:
        fprintf(stderr,
          "Error: There was an error, please try again.\n\n"
          "Try '%s --help' for more information.\n",
          argv[0]);

        return EXIT_FAILURE;
    }
  }

  if (help_requested) {
    help(argv[0]);
    return EXIT_SUCCESS;
  }

  if (argc - optind != 1) {
    fprintf(stderr,
      "Error: Too many arguments.\n\n"
      "Try '%s --help' for more information.\n",
      argv[0]);

    return EXIT_FAILURE;
  }

  char *filename = argv[optind];

  return find_matches(".", filename);
}
