/* TagOperations.cpp
 * Provides functions for the TagOperations class, used to provide
 * static methods for accessing, modifying, and otherwise working with
 * tags based on arguments passed to tiger.
 */

/* Stdlib includes */
#include <cstring>
#include <iostream>
#include <vector>

/* Local includes */
#include "ArgumentType.hpp"
#include "Tag.hpp"

/* Include self */
#include "TagOperations.hpp"

/* Namespaces */
using namespace std;

/* public: */

/* Performs actions depending on the arguments passed to the program. */
void TagOperations::parse_args(int argc, char* argv[]) {
    if (argc == 1 || strcmp(argv[1], "help") == 0) {
        // Show help
        cout << "tiger is a program for tagging and organizing files."
                << endl << endl
                << "Commands:" << endl
                << "    help: Display this screen." << endl
                << "    tag: Add a tag to a file." << endl
                << "    search: Look up files with a certain tag." << endl;
                << "    list: List all tags, and the files they are "
                << "attached to." << endl;
    } else if (strcmp(argv[1], "tag") == 0) {
        std::vector<std::string> args(argv + 2, argv + argc);
        tag(args);
    } else if (strcmp(argv[1], "search") == 0) {
        std::vector<std::string> args(argv + 2, argv + argc);
        search(args);
    } else if (strcmp(argv[1], "list") == 0) {
        list();
    }
}

/* Responsible for adding tags to files based on command-line arguments. */
void TagOperations::tag(std::vector<std::string> args) {
    std::vector<std::string> tagNames;
    std::vector<std::string> files;
    ArgumentType type;
    
    // Make lists of tags to be applied, and files to apply them to
    for (std::vector<std::string>::iterator iter = args.begin();
            iter != args.end(); iter++) {
        if (*iter == "-t")
            type = TAG_ARG;
        else if (*iter == "-f")
            type = FILE_ARG;
        else if (type == TAG_ARG)
            tagNames.push_back(*iter);
        else if (type == FILE_ARG)
            files.push_back(*iter);
    }
    
    // Fill a vector of needed tags from the tag names
    std::vector<Tag> tags;
    
    // For each tag, apply it to the relevant files
    for (std::vector<Tag>::iterator tagsIter = tags.begin();
            tagsIter != tags.end(); tagsIter++)
        for (std::vector<std::string>::iterator filesIter = files.begin();
                filesIter != files.end(); filesIter++)
            (*tagsIter).addFile(*filesIter);
    
    // TODO: how to return results of operation?
}

/* Reponsible for looking up files based on command-line arguments. */
std::vector<std::vector<std::string>> TagOperations::search(
        std::vector<std::string> args) {
    std::vector<std::vector<std::string>> results
    
    // For each specified tag...
    for (auto iter = args.begin(); iter < args.end(); iter++)
        results.push_back(tagMap.at(*iter).files);
    
    return vec;
}

/* Outputs all tags, and the files they are attached to. */
void TagOperations::list(void) {
    
}
