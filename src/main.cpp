/* main.cpp
 * Provides top-level functions for tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <iostream>

/* Namespaces */
using namespace std;

/* Function declarations (TODO: move these somewhere else) */
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
        // args after "-t": tags to add
        // args after "-f": files to add tags to
        int collectingType;
        
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-t") == 0)
                // TODO: set CollectingType using an enum
                cout << "Switching to tags" << endl;
            else if (strcmp(argv[i], "-f") == 0)
                // TODO: set CollectingType using an enum
                cout << "Switching to files" << endl;
        }
    } else if (strcmp(argv[1], "search") == 0) { /* Search by tag */
        // argv[2]: tag to search for
    }
}
