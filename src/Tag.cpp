/* Tag.cpp
 * Provides functions for the Tag class used to represent tags, which hold
 * lists of files they belong to.
 */

/* Stdlib includes */
#include <string>
#include <vector>

/* Local includes */
#include "Tag.hpp"

/* Adds the tag to a file. */
void Tag::addFile(std::string path) {
    files.push_back(path);
}

/* Removes the tag from a file. */
bool Tag::removeFile(std::string path) {
    for (std::vector<std::string>::iterator iter = files.begin();
            iter != files.end(); iter++) {
        if (*iter == path) {
            files.erase(iter);
            return true;
        }
    }
    
    return false;
}
