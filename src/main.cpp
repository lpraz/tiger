/* main.cpp
 * Provides top-level functions for tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <iostream>
#include <vector>

/* Local includes */
#include "Tag.hpp"
#include "TagOperations.hpp"

/* Namespaces */
using namespace std;

/* Function declarations (TODO: move these somewhere else) */
void parse_args(int argc, char* argv[]);

/* Main function. */
int main(int argc, char* argv[]) {
    std::vector<Tag> tags;
    
    // TODO: fill tags from file
    
    // Do the expected action based on arguments
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
        std::vector<std::string> args(argv + 2, argv + argc);
        TagOperations::tag(args);
    } else if (strcmp(argv[1], "search") == 0) {
        std::vector<std::string> args(argv + 2, argv + argc);
        TagOperations::search(args);
    }
}
