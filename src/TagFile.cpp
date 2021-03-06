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
            std::string tag = readQuotedString(tagFileInputStream);
            std::vector<std::string> files;
            
            while (tagFileInputStream.peek() != '\n' &&
                    tagFileInputStream.good())
                files.push_back(readQuotedString(tagFileInputStream));
            
            if (files.size() > 0)
                tagDict.insert({tag, files});
        }
    }
    
    /**
     * Reads the next string surrounded by a pair of a quotes,
     * taking whitespace into account.
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
            
            resultStream << nextChar;
        
            if (stream.eof())
                break;
        }
        
        return resultStream.str();
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
