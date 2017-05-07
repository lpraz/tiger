/* Tag.hpp
 * Header for the Tag class used to represent tags, which hold lists of
 * files they belong to.
 */

/* Define guard */
#ifndef TAG_HPP
#define TAG_HPP

/* Stdlib includes */
#include <string>
#include <vector>

class Tag {
    private:
        std::vector<std::string> files;
    public:
        bool addFile(std::string);
        bool removeFile(std::string);
        std::vector<std::string>::iterator tagIsOnFile(std::string);
        std::vector<std::string> getFiles();
};

#endif
