/* TagOperations.hpp
 * Header for the TagOperations class, used to provide static methods
 * for accessing, modifying, and otherwise working with tags based on
 * arguments passed to tiger.
 */

/* Define guard */
#ifndef TAGOPERATIONS_HPP
#define TAGOPERATIONS_HPP

/* Stdlib includes */
#include <vector>

/* Local includes */
#include "Tag.hpp"

class TagOperations {
    public:
        static bool tag(std::vector<std::string>);
        static std::vector<std::string> search(std::vector<std::string>);
};

#endif
