/* TagFile.cpp
 * Provides operations related to the .tiger file used for storing tags,
 * and represents it as a class.
 */

/* Stdlib includes */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <unordered_map>

/* Local includes */
#include "Tag.hpp"

/* Include self */
#include "TagFile.hpp"

/* Namespaces */
using namespace std;

/* TagFile constructor. */
TagFile::TagFile(void) {
    // Get path of .tiger file from environment variables
    path = getenv("HOME");
    
    // If that doesn't work, get it from password directory
    if (path == NULL)
        path = getpwuid(getuid())->pw_dir;
    
    // Now, open a file with our newfound path
    file.open(path);
}

/* TagFile destructor. */
TagFile::~TagFile(void) {
    // Close the file.
    file.close();
}

/* Gets all the tags in the file and returns them in a hash table. */
std::unordered_map<std::string, Tag> TagFile::getTags() {
    std::unordered_map<std::string, Tag> tags;
    Tag tempTag;
    std::string tempTagName;
    std::string tempTagPath;
    
    while (!file.eof()) {
        // Clear tempTagName
        tempTagName = "";
        
        // Discard opening quote of tag name
        file.get();
        
        // Get tempTagName up to closing quote, put into tempTag
        getline(file, tempTagName);
        tempTag.setName(tempTagName);
        
        // Discard closing quote
        file.get();
        
        // Each tag's file list ends in a period, read up to there
        while (file.peek() != '.') {
            // Clear tempTagPath
            tempTagPath = "";
            
            // Discard opening quote of file path
            file.get();
            
            // Get tempTagPath up to closing quote, put into tempTag
            while (file.peek() != '\"')
                tempTagPath += file.get();
            
            tempTag.addFile(tempTagPath);
            
            // Discard until next opening quote or period (end of tag)
            while (file.peek() != '\"' || file.peek() != '.')
                file.get();
        }
        
        // Get/discard to next entry or EOF
        while (file.peek() != EOF || file.peek() != '\"')
            file.get();
    }
}

/* Saves all tags in the hash table to the file. */
void TagFile::saveTags(std::unordered_map<std::string, Tag> tags) {
    for (auto tag = tags.begin(); tag != tags.end(); tag++) {
        // "<tagname>":
        file << "\"" << (*tag).first << "\":";
        
        //  "<path>",
        for (auto path = (*tag).second.getFiles().begin();
                path != (*tag).second.getFiles().end(); path++)
            file << " \"" << *path << "\",";
        
        // Backspace, end with period, new line
        file << "\b." << endl;
    }
}
