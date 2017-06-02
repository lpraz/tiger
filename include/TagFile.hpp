/**
 * @file
 * author lpraz
 *
 * @section DESCRIPTION
 * Header file for the TagFile class.
 */

#ifndef TAGFILE_HPP
#define TAGFILE_HPP

// Stdlib includes
#include <string>
#include <unordered_map>
#include <vector>

namespace Tiger {
    /**
     * Represents, and provides access to, tiger's tag file, which holds
     * all tags and the files they are attached to.
     */
    class TagFile {
        private:
            std::unordered_map<std::string, std::vector<std::string>> tags;
        
        public:
            TagFile();
            ~TagFile();
            std::unordered_map<std::string, std::vector<std::string>>
                    getTags(void);
    };
}

#endif
