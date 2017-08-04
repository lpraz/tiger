/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Header file for tiger's operations functions, which are the top-level
 * functions for each of tiger's commands.
 * Any operations functions will be placed in the Tiger::Operations
 * namespace.
 */

// Stdlib includes
#include <string>
#include <unordered_map>
#include <vector>

// Local includes
#include "Command.hpp"

namespace Tiger {
    class Operations {
        private:
            static std::string toFullPath(std::string shortPath);
            static void toVectorizedPath(std::string path,
                    std::vector<std::string>& pathVector);
            static std::string readSubDirectory(std::istream& stream);
            static void addTagToFile(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict, std::string tag,
                    std::string file);
            static void removeTagFromFile(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict, std::string tag,
                    std::string file);
        
        public:
            static void add(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict,
                    std::vector<std::string> tags,
                    std::vector<std::string> files);
            static void remove(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict,
                    std::vector<std::string> tags,
                    std::vector<std::string> files);
            static void search(std::unordered_map<std::string,
                    std::vector<std::string>> tagDict,
                    std::vector<std::string> tags,
                    std::vector<std::string> files);
            static void list(std::unordered_map<std::string,
                    std::vector<std::string>> tagDict);
            static void help(void);
    };
}
