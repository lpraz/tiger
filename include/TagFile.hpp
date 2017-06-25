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
#include <fstream>
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
            const std::string tagFilePath = "/.tiger";
            std::string homeDirectory;
            std::unordered_map<std::string, std::vector<std::string>> tags;
            
            std::string readQuotedString(std::istream &stream);
        
        public:
            TagFile();
            void close();
            //~TagFile();
            std::unordered_map<std::string, std::vector<std::string>>&
                    getTags(void);
    };
}

#endif
