/* TagOperations.cpp
 * Provides functions for the TagOperations class, used to provide
 * static methods for accessing, modifying, and otherwise working with
 * tags based on arguments passed to tiger.
 */

/* Stdlib includes */
#include <vector>

/* Local includes */
#include "ArgumentType.hpp"
#include "Tag.hpp"

/* Include self */
#include "TagOperations.hpp"

/* public: */
/* Responsible for adding tags to files based on command-line arguments. */
bool TagOperations::tag(std::vector<std::string> args) {
    std::vector<std::string> tags;
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
            tags.push_back(*iter);
        else if (type == FILE_ARG)
            files.push_back(*iter);
    }
    
    return false; // TODO: not implemented
}

/* Reponsible for looking up files based on command-line arguments. */
std::vector<std::string> TagOperations::search(
        std::vector<std::string> args) {
    std::vector<std::string> vec;
    return vec; // TODO: not implemented
}
