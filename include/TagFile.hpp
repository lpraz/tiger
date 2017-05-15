/* TagFile.hpp
 * Header for the TagFile class used to represent the .tiger file used for
 * storing tags.
 */

// Define guard
#ifndef TAGFILE_HPP
#define TAGFILE_HPP

/* Stdlib includes */
#include <fstream>
#include <unordered_map>

/* Local includes */
#include "TagFile.hpp"

class TagFile {
    private:
        char *path;
        std::fstream file;
    
    public:
        TagFile();
        ~TagFile();
        std::unordered_map<std::string, Tag> getTags();
};

#endif
