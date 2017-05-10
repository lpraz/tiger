/* Tag.cpp
 * Provides functions for the Tag class used to represent tags, which hold
 * lists of files they belong to.
 */

/* Stdlib includes */
#include <algorithm>
#include <string>
#include <vector>

/* Include self */
#include "Tag.hpp"

/* public: */

/* Attempts to add the tag to a file, returns whether it was added
 * (i.e. the tag wasn't already on the file).
 */
bool Tag::addFile(std::string path) {
    // Get iterator resulting from a search for path
    std::vector<std::string>::iterator iter = isOnFile(path);
    
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
    std::vector<std::string>::iterator iter = isOnFile(path);
    
    // If an iterator was returned, remove from files and return success
    if (iter != files.end()) {
        files.erase(iter);
        return true;
    }
    
    // Else, return failure
    return false;
}

/* Returns whether a given file has this Tag. */
std::vector<std::string>::iterator Tag::isOnFile(std::string path) {
    // Get result of a search in files for path
    std::vector<std::string>::iterator iter = std::find(
            files.begin(), files.end(), path);
    
    // If path is in files, return success
    if (*iter == path)
        return iter;
    
    // Else, return failure
    return files.end();
}

/* Returns a list of files that the Tag is applied to (as a copy). */
std::vector<std::string> Tag::getFiles() {
    // Make a new vector containing everything in files
    std::vector<std::string> filesCopy(files);
    return filesCopy;
}

/* Returns a list of Tags that are applied to a given file. */
std::vector<Tag> Tag::getTagsOnFile(std::string path,
        std::vector<Tag> possibleTags) {
    // Make a vector to hold Tags
    std::vector<Tag> tagsOnFile;
    
    // Check each Tag for path, add it if it exists
    for (std::vector<Tag>::iterator iter = possibleTags.begin();
            iter != possibleTags.end(); iter++)
        if ((*iter).isOnFile(path) != (*iter).files.end())
            tagsOnFile.push_back(*iter);
    
    return tagsOnFile;
}
