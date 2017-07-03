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
#include "Operations.hpp"

// Include own header
#include "TagFile.hpp"

namespace Tiger {
    // private:
    
    /**
     * Reads the next string found within a pair of double quotation
     * marks ("), taking whitespace into account.
     *
     * @param stream The stream to read from.
     * @returns The string that was read.
     */
    std::string TagFile::readQuotedString(std::istream& stream) {
        stream >> std::noskipws;
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
        // TODO: actually read the results into the dictionary
        std::ifstream tagFileInputStream;
        homeDirectory = getenv("HOME");
        tagFileInputStream.open(homeDirectory + tagFilePath);
        tagFileInputStream >> std::noskipws;
        
        if (!tagFileInputStream.good())
            return;
        
        while (tagFileInputStream.eof()) {
            std::string tag = readQuotedString(tagFileInputStream);
            std::vector<std::string> files;
            
            while (tagFileInputStream.peek() != '\n')
                files.push_back(readQuotedString(tagFileInputStream));
            
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
