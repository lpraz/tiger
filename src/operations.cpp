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
#include <algorithm>
#include <iostream>

// Include own header
#include "operations.hpp"

namespace Tiger {
    namespace Operations {
        /**
         * Adds the specified tags to the specified files.
         * Called by the user with the "add" command.
         *
         * @param tags The hash table of tags to modify.
         * @param command The command object containing the tags to be
         *                added, and the files to be tagged.
         */
        void addTags(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command) {
            for (auto file : command.getFiles()) {
                for (auto tag : command.getTags()) {
                    if (tags.find(tag) == tags.end())
                        tags[tag] = std::vector<std::string> {file};
                    else
                        tags[tag].push_back(file);
                }
            }
        }
        
        /**
         * Removes the specified tags from the specified files.
         * Called by the user with the "remove" command.
         *
         * @param tags The hash table of tags to modify.
         * @param command The command object containing the tags to be
         *                added, and the files to be tagged.
         */
        void removeTags(std::unordered_map<std::string,
                std::vector<std::string>> tags, Tiger::Command command) {
        }
        
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
            for (auto tag : command.getTags()) {
                std::cout << tag << ":\n\t";
                
                auto tagFiles = tags.find(tag);
                if (tagFiles != tags.end()) {
                    for (auto tagFile = tagFiles->second.begin();
                            tagFile != tagFiles->second.end(); tagFile++) {
                        if (tagFile != tagFiles->second.begin())
                            std::cout << ",\n\t";
                        
                        std::cout << *tagFile;
                    }
                }
            }
            
            std::cout << "=== Files ===\n";
            for (auto file : command.getFiles()) {
                std::cout << file << ":\n\t";
                
                bool first = true;
                for (auto tag : tags) {
                    if (std::find(tag.second.begin(), tag.second.end(),
                            file) != tag.second.end()) {
                        if (first)
                            first = false;
                        else
                            std::cout << ",\n\t";
                        
                        std::cout << tag.first;
                    }
                }
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
                        std::cout << ",\n\t";
                    
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
