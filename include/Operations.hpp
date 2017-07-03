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
            static void addTagToFile(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict, std::string tag,
                    std::string file);
            static void removeTagFromFile(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict, std::string tag,
                    std::string file);
        
        public:
            // TODO: not take a Command, but vectors instead
            static void addTags(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict,
                    Tiger::Command command);
            static void removeTags(std::unordered_map<std::string,
                    std::vector<std::string>>& tagDict,
                    Tiger::Command command);
            static void search(std::unordered_map<std::string,
                    std::vector<std::string>> tagDict,
                    Tiger::Command command);
            static void displayListOfTags(std::unordered_map<std::string,
                    std::vector<std::string>> tagDict);
            static void displayHelp(void);
    };
}
