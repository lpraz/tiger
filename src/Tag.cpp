/* Tag.cpp
 * Provides functions for the Tag class used to represent tags, which hold
 * lists of files they belong to.
 */

/* Stdlib includes */
#include <algorithm>
#include <string>
#include <vector>

/* Local includes */
#include "Tag.hpp"

/* public: */

/* Attempts to add the tag to a file, returns whether it was added
 * (i.e. the tag wasn't already on the file).
 */
bool Tag::addFile(std::string path) {
    // Get result of a search in files for path
    std::vector<std::string>::iterator iter = std::find(
            files.begin(), files.end(), path);
    
    // If path isn't in files, add it and return success
    if (*iter != path) {
        files.push_back(path);
        return true;
    }
    
    // Else, return failure
    return false;
}

/* Attempts to remove the tag from a file, returns whether it was
 * deleted (i.e. the tag was on the file).
 */
bool Tag::removeFile(std::string path) {
    // Get result of a search in files for path
    std::vector<std::string>::iterator iter = std::find(
            files.begin(), files.end(), path);
    
    // If path is in files, remove it and return success
    if (*iter == path) {
        files.erase(iter);
        return true;
    }
    
    // Else, return failure
    return false;
}
