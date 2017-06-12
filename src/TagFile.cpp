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
        homeDirectory = getenv("HOME");
    }
    
    /**
     * Closes a TagFile, and saves any changes to TagFile::tags to disk.
     */
    TagFile::~TagFile() {
        bool firstTag = true;
        
        for (auto tag : tags) {
            if (firstTag)
                firstTag = false;
            else
            tagFile << "\n";
            
            tagFile << "\"" << tag.first << "\":";
            bool firstFile = true;
            
            for (auto file : tag.second) {
                if (firstFile)
                    firstFile = false;
                else
                    tagFile << ", ";
                
                tagFile << "\"" << file << "\"";
            }
        }
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
}
