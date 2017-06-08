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
    namespace Operations {
        void addTags(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command);
        void removeTags(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command);
        void search(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command);
        void displayListOfTags(std::unordered_map<std::string,
                std::vector<std::string>> tags);
        void displayHelp(void);
    }
}
