/* TagFile.hpp
 * Header for the TagFile class used to represent the .tiger file used for
 * storing tags.
 */

// Define guard
#ifndef TAGFILE_HPP
#define TAGFILE_HPP

/* Local includes */
#include "TagFile.hpp"

class TagFile {
    private:
        char *path;
    
    public:
        TagFile();
        Tag *getTag(std::string);
};

#endif
