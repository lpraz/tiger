/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines methods for the TagFile class.
 */

// Stdlib includes
#include <algorithm>
#include <iostream>
#include <sstream>

// Local includes
#include "helpers.hpp"
#include "Operations.hpp"

// Include own header
#include "TagFile.hpp"

namespace Tiger {
    /**
     * Initializes (constructs) a TagFile by reading its contents from
     * disk, if they exist.
     */
    TagFile::TagFile() {
        std::ifstream tagFileInputStream;
        homeDirectory = getenv("HOME");
        tagFileInputStream.open(homeDirectory + tagFilePath);
        tagFileInputStream >> std::noskipws;
        
        if (!tagFileInputStream.good())
            return;
        
        while (tagFileInputStream.good()) {
            std::string tag = 
                    Tiger::Helpers::readDelimitedString(tagFileInputStream,
                    '"');
            std::vector<std::string> files;
            
            while (tagFileInputStream.peek() != '\n' &&
                    tagFileInputStream.good())
                files.push_back(
                    Tiger::Helpers::readDelimitedString(tagFileInputStream,
                    '"'));
            
            if (files.size() > 0)
                tagDict.insert({tag, files});
        }
    }
    
    /**
     * Saves any changes to TagFile::tags to disk.
     */
    void TagFile::close() {
        std::ofstream tagFileOutputStream;
        tagFileOutputStream.open(homeDirectory + tagFilePath);
        
        bool firstTag = true;
        
        for (auto tag : tagDict) {
            if (firstTag)
                firstTag = false;
            else
                tagFileOutputStream << "\n";
            
            tagFileOutputStream << "\"" << tag.first << "\":";
            bool firstFile = true;
            
            for (auto file : tag.second) {
                if (firstFile)
                    firstFile = false;
                else
                    tagFileOutputStream << ",";
                
                tagFileOutputStream << "\"" << file << "\"";
            }
        }
    }
    
    /**
     * Accessor method for the TagFile::tags field.
     *
     * @returns The current hash table of strings (tags) and vectors of
     *          strings (files) held in TagFile::tagDict.
     */
    std::unordered_map<std::string, std::vector<std::string>>&
            TagFile::getTags(void) {
        return tagDict;
    }
}
