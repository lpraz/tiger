/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Header file for the Command class.
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

// Stdlib includes
#include <string>
#include <vector>

namespace Tiger {
    /**
     * Represents a command given to tiger.
     */
    class Command {
        public:
            /**
             * Represents the possible actions to be given in a command.
             */
            enum Action {
                HELP,
                ADD,
                REMOVE,
                SEARCH,
                LIST
            };

        private:
            Action action;
            std::vector<std::string> tags;
            std::vector<std::string> files;
        
        public:
            Command(std::vector<std::string> arguments);
            Action getAction();
            std::vector<std::string> getTags();
            std::vector<std::string> getFiles();
    };
}

#endif
