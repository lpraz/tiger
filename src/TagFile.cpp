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

// Include own header
#include "TagFile.hpp"

namespace Tiger {
    // private:
    
    /**
     * Reads the next string found within a pair of double quotation
     * marks (").
     *
     * @param stream The stream to read from.
     * @returns The string that was read.
     */
    std::string TagFile::readQuotedString(std::istream& stream) {
        // TODO: ignores spaces in result?
        std::stringstream resultStream;
        char nextChar;
        
        while (stream >> nextChar)
            if (nextChar == '"')
                break;
        
        while (stream >> nextChar) {
            if (nextChar == '"')
                break;
            else
                resultStream << nextChar;
        }
        
        return resultStream.str();
    }
    
    // public:
    
    /**
     * Initializes (constructs) a TagFile by reading its contents from
     * disk, if they exist.
     */
    TagFile::TagFile() {
        // TODO: fix infinite loop when reading non-empty file here
        std::ifstream tagFileInputStream;
        homeDirectory = getenv("HOME");
        tagFileInputStream.open(homeDirectory + tagFilePath);
        
        if (!tagFileInputStream.good())
            return;
        
        while (true) {
            std::string tag = readQuotedString(tagFileInputStream);
            std::vector<std::string> files;
            std::cout << "ayy";
            
            while (tagFileInputStream.peek() != '\n')
                files.push_back(readQuotedString(tagFileInputStream));
            
            tags.insert({tag, files});
            
            if (tagFileInputStream.peek() == EOF)
                break;
        }
    }
    
    /**
     * Saves any changes to TagFile::tags to disk.
     */
    void TagFile::close() {
        std::ofstream tagFileOutputStream;
        tagFileOutputStream.open(homeDirectory + tagFilePath);
        
        bool firstTag = true;
        
        for (auto tag : tags) {
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
     *          strings (files) held in TagFile::tags.
     */
    std::unordered_map<std::string, std::vector<std::string>>&
            TagFile::getTags(void) {
        return tags;
    }
}
