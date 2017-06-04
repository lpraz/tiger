/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines methods for the TagFile class.
 */

// Stdlib includes
#include <algorithm>

// Include own header
#include "TagFile.hpp"

namespace Tiger {
    /**
     * Initializes a TagFile.
     */
    TagFile::TagFile() {
    }
    
    /**
     * Closes a TagFile, and saves any changes to TagFile::tags to disk.
     */
    TagFile::~TagFile() {
    }
    
    /**
     * Accessor method for the TagFile::tags field.
     *
     * @returns The current hash table of strings (tags) and vectors of
     *          strings (files) held in TagFile::tags.
     */
    std::unordered_map<std::string, std::vector<std::string>>
            TagFile::getTags(void) {
        return tags;
    }
    
    /**
     * Adds a tag to a file.
     * In terms of the internal operations of the class, it more so
     * adds a file to a tag, but the end-user should see no difference.
     * If the tag doesn't exist, it will be added first, then the file
     * added to its list.
     *
     * @param tag The tag to be added.
     * @param file The file to add the tag to.
     */
    void TagFile::addTagToFile(std::string tag, std::string file) {
        if (tags.find(tag) == tags.end())
            tags[tag] = std::vector<std::string> {file};
        else
            tags[tag].push_back(file);
    }
    
    /**
     * Removes a tag from a file.
     * In terms of the internal operations of the class, it more so
     * removes a file from a tag, but the end-user should see no
     * difference. If the tag would have no more files after having
     * the file removed, it will be deleted.
     *
     * @param tag The tag to be removed.
     * @param file The file to remove the tag from.
     * @returns True if the file has the tag, false otherwise.
     */
    bool TagFile::removeTagFromFile(std::string tag, std::string file) {
        if (tags.find(tag) == tags.end()) {
            auto index = std::remove(tags[tag].begin(), tags[tag].end(),
                    file);
            if (index != tags[tag].end()) {
                tags[tag].erase(index);
                return true;
            }
        }
        
        return false;
    }
}
