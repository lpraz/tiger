/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines tiger's operations functions, which are the top-level functions
 * for each of tiger's commands.
 * Any operations functions will be placed in the Tiger::Operations
 * namespace.
 */

// Stdlib includes
#include <iostream>

// Include own header
#include "operations.hpp"

namespace Tiger {
    namespace Operations {
        /**
         * Displays a list of all files with given tags, and all tags
         * attached to given files.
         * Called by the user with the "search" command.
         *
         * @param tags The hash table of tags to search through.
         * @param command The command object containing the arguments
         *                to base the search on.
         */
        void search(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command) {
            std::cout << "=== Tags ===\n";
            for (auto iter : command.getTags()) {
               std::cout << iter << ":\n";
            }
            
            std::cout << "=== Files ===\n";
            for (auto iter : command.getFiles()) {
                
            }
        }
        
        /**
         * Displays a list of all tags, and all files that have those
         * tags.
         * Called by the user with the "list" command.
         *
         * @param tags The hash table of tags to output.
         */
        void displayListOfTags(std::unordered_map<std::string,
                std::vector<std::string>> tags) {
            for (auto tag : tags) {
                std::cout << tag.first << ":\n\t";
                
                for (auto file = tag.second.begin();
                        file != tag.second.end(); file++) {
                    if (file != tag.second.begin())
                        std::cout << ",\n";
                    
                    std::cout << *file;
                }
                
                std::cout << std::endl;
            }
        }
        
        /**
         * Displays the help for the application and its commands.
         * Called by the user with the "help" command, or by specifying
         * no command at all.
         */
        void displayHelp(void) {
            std::string helpText =
                    "tiger is a program for tagging and organizing files.\n"
                    "Commands:\n"
                    "    help: Display this screen.\n"
                    "    tag: Add a tag to a file.\n"
                    "    search: Look up files with a certain tag.\n"
                    "    list: Display all tags on your system, and all\n"
                    "          of the files they are attached to.\n";
            
            std::cout << helpText;
        }
    }
}
