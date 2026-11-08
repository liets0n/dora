#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "./../include/dir.h"
#include "./../include/usage.h"

int main(const int argc, char *argv[]) {
  const struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"directory", required_argument, NULL, 'd'},
    {"name", required_argument, NULL, 'n'},
    {NULL, 0, NULL, 0}
  };

  int option;

  short help_requested = 0;
  char *dir = NULL;
  char *name = NULL;

  while ((option = getopt_long(argc, argv, ":hd:n:", long_options, NULL)) != -1) {
    switch (option) {
      case 'h':
        help_requested = 1;
        break;
      case 'd':
        dir = optarg;
        break;
      case 'n':
        name = optarg;
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
          "Usage:\n"
          "\t%s -d <directory>\n"
          "\t%s -d <directory> -n <name>\n\n"
          "Try '%s --help' for more information.\n",
          optopt, argv[0], argv[0], argv[0]);

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

  if (argc - optind != 0) {
    fprintf(stderr,
      "Error: Unknown argument.\n\n"
      "Usage:\n"
      "\t%s -d <directory>\n"
      "\t%s -d <directory> -n <name>\n\n"
      "Try '%s --help' for more information.\n",
      argv[0], argv[0], argv[0]);

    return EXIT_FAILURE;
  }

  if (argc - optind == 0 && dir == NULL && name == NULL) {
    find_matches(".", NULL);
  } else if (argc - optind == 0 && dir == NULL && name != NULL) {
    find_matches(".", name);
  } else if (argc - optind == 0 && dir != NULL && name == NULL) {
    find_matches(dir, NULL);
  } else if (argc - optind == 0 && dir != NULL && name != NULL) {
    find_matches(dir, name);
  } else {
    fprintf(stderr,
      "Error: Unknown argument...\n\n"
      "Usage:\n"
      "\t%s -d <directory>\n"
      "\t%s -d <directory> -n <name>\n\n"
      "Try '%s --help' for more information.\n",
      argv[0], argv[0], argv[0]);

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
