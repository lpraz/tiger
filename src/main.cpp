/* main.cpp
 * Provides top-level functions for tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <iostream>

/* Namespaces */
using namespace std;

/* Function declarations */
void parse_args(int argc, char* argv[]);

/* Main function. */
int main(int argc, char* argv[]) {
    parse_args(argc, argv);
    return 0;
}

/* Performs actions depending on the arguments passed to the program. */
void parse_args(int argc, char* argv[]) {
    if (argc == 1) { /* No args except for program name, give help */
        cout << "tiger is a program for tagging and organizing files."
                << endl << endl
                << "Commands:" << endl
                << "    tag: Add a tag to a file." << endl
                << "    search: Look up files with a certain tag." << endl;
    } else if (strcmp(argv[1], "tag") == 0) { /* Tag a file */
        /* argv[2]: file */
        /* argv[3]: tag */
    } else if (strcmp(argv[1], "search") == 0) { /* Search by tag */
        /* argv[2]: tag */
    }

/* For future reference: use getenv("HOME") to get home directory
 * for writing the tag file. If that doesn't work, use
 * gwetpwuid(getuid())->pw_dir
 */
}
