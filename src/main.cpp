/* main.cpp
 * Provides top-level functions for tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <iostream>
#include <vector>

/* Local includes */
#include "ArgumentType.hpp"

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
    if (argc == 1 || strcmp(argv[1], "help") == 0) {
        // Show help
        cout << "tiger is a program for tagging and organizing files."
                << endl << endl
                << "Commands:" << endl
                << "    help: Display this screen." << endl
                << "    tag: Add a tag to a file." << endl
                << "    search: Look up files with a certain tag." << endl;
    } else if (strcmp(argv[1], "tag") == 0) {
        // Add tag(s) to file(s)
        
        // Specification:
        // args after "-t": tags to add
        // args after "-f": files to add tags to
        
        std::vector<std::string> tags;
        std::vector<std::string> files;
        ArgumentType type;
        
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-t") == 0)
                type = TAG_ARG;
            else if (strcmp(argv[i], "-f") == 0)
                type = FILE_ARG;
            else if (type == TAG_ARG)
                tags.push_back(argv[i]);
            else if (type == FILE_ARG)
                files.push_back(argv[i]);
        }
    } else if (strcmp(argv[1], "search") == 0) {
        // Search for files with a certain tag(s)
        
        // Specification:
        // args after argv[1]: tags to search for
    }
}
