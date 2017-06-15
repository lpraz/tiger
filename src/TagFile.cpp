/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines methods for the TagFile class.
 */

// Stdlib includes
#include <algorithm>
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
    std::string TagFile::readQuotedString(std::istream &stream) {
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
     * Initializes a TagFile.
     */
    TagFile::TagFile() {
        homeDirectory = getenv("HOME");
        tagFileStream.open(homeDirectory + tagFilePath);
        
        std::string currentLine;
        
        while (!tagFileStream.eof()) {
            getline(tagFileStream, currentLine);
            std::stringstream currentLineStream(currentLine);
            
            readQuotedString(tagFileStream); // into key
            
            while (tagFileStream.peek() != '\n')
                readQuotedString(tagFileStream); // into values
        }
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
                tagFileStream << "\n";
            
            tagFileStream << "\"" << tag.first << "\":";
            bool firstFile = true;
            
            for (auto file : tag.second) {
                if (firstFile)
                    firstFile = false;
                else
                    tagFileStream << ", ";
                
                tagFileStream << "\"" << file << "\"";
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
