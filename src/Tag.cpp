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
    // Get iterator resulting from a search for path
    std::vector<std::string>::iterator iter = tagIsOnFile(path);
    
    // If no iterator returned, add path to files and return success
    if (iter == files.end()) {
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
    // Get iterator resulting from a search for path
    std::vector<std::string>::iterator iter = tagIsOnFile(path);
    
    // If an iterator was returned, remove from files and return success
    if (iter != files.end()) {
        files.erase(iter);
        return true;
    }
    
    // Else, return failure
    return false;
}

/* Returns whether a given file has this Tag. */
std::vector<std::string>::iterator Tag::tagIsOnFile(std::string path) {
    // Get result of a search in files for path
    std::vector<std::string>::iterator iter = std::find(
            files.begin(), files.end(), path);
    
    // If path is in files, return success
    if (*iter == path)
        return iter;
    
    // Else, return failure
    return files.end();
}

/* Returns a list of files that the tag is applied to (as a copy). */
std::vector<std::string> Tag::getFiles() {
    // Make a new vector containing everything in files
    std::vector<std::string> filesCopy(files);
    return filesCopy;
}
