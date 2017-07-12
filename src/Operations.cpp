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
#include "Operations.hpp"

namespace Tiger {
    /**
     * Adds a tag to a file.
     * In terms of the internal operations of the class, it more so
     * adds a file to a tag, but the end-user should see no difference.
     * If the tag doesn't exist, it will be added first, then the file
     * added to its list.
     *
     * @param tagDict The hash table of tags to modify.
     * @param tag The tag to be added.
     * @param file The file to add the tag to.
     */
    void Operations::addTagToFile(std::unordered_map<std::string,
            std::vector<std::string>>& tagDict, std::string tag,
            std::string file) {
        if (tagDict.find(tag) == tagDict.end()) {
            tagDict.insert({tag, std::vector<std::string> {file}});
        } else {
            auto filePosition = std::find(tagDict[tag].begin(),
                    tagDict[tag].end(), file);
            if (filePosition == tagDict[tag].end())
                tagDict[tag].push_back(file);
        }
    }
    
    /**
     * Removes a tag from a file.
     * In terms of the internal operations of the class, it more so
     * removes a file from a tag, but the end-user should see no
     * difference. If the tag would have no more files after having
     * the file removed, it will be deleted.
     *
     * @param tagDict The hash table of tags to modify.
     * @param tag The tag to be removed.
     * @param file The file to remove the tag from.
     */
    void Operations::removeTagFromFile(std::unordered_map<std::string,
            std::vector<std::string>>& tagDict, std::string tag,
            std::string file) {
        if (tagDict.find(tag) != tagDict.end()) {
            auto index = std::remove(tagDict[tag].begin(),
                    tagDict[tag].end(), file);
            
            if (index != tagDict[tag].end()) {
                tagDict[tag].erase(index);
                
                if (tagDict[tag].size() == 0)
                    tagDict.erase(tag);
            }
        }
    }
    
    /**
     * Adds the specified tags to the specified files.
     * Called by the user with the "add" command.
     *
     * @param tagDict The hash table of tags to modify.
     * @param command The command object containing the tags to be
     *                added, and the files to be tagged.
     */
    void Operations::addTags(std::unordered_map<std::string,
            std::vector<std::string>>& tagDict, std::vector<std::string> tags,
            std::vector<std::string> files) {
        for (auto file : files) {
            for (auto tag : tags) {
                addTagToFile(tagDict, tag, file);
            }
        }
    }
    
    /**
     * Removes the specified tags from the specified files.
     * Called by the user with the "remove" command.
     *
     * @param tagDict The hash table of tags to modify.
     * @param command The command object containing the tags to be
     *                added, and the files to be tagged.
     */
    void Operations::removeTags(std::unordered_map<std::string,
            std::vector<std::string>>& tagDict, std::vector<std::string> tags,
            std::vector<std::string> files) {
        for (auto file : files) {
            for (auto tag : tags) {
                removeTagFromFile(tagDict, tag, file);
            }
        }
    }
    
    /**
     * Displays a list of all files with given tags, and all tags
     * attached to given files.
     * Called by the user with the "search" command.
     *
     * @param tagDict The hash table of tags to search through.
     * @param command The command object containing the arguments
     *                to base the search on.
     */
    void Operations::search(std::unordered_map<std::string,
            std::vector<std::string>> tagDict, std::vector<std::string> tags,
            std::vector<std::string> files) {
        std::cout << "=== Tags ===\n";
        for (auto tag : tags) {
            std::cout << tag << ":\n\t";
            
            auto tagFiles = tagDict.find(tag);
            if (tagFiles != tagDict.end()) {
                for (auto tagFile = tagFiles->second.begin();
                        tagFile != tagFiles->second.end(); tagFile++) {
                    if (tagFile != tagFiles->second.begin())
                        std::cout << ",\n\t";
                    
                    std::cout << *tagFile;
                }
            }
        }
        
        std::cout << "=== Files ===\n";
        for (auto file : files) {
            std::cout << file << ":\n\t";
            
            bool first = true;
            for (auto tag : tagDict) {
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
        
        std::cout << "\n";
    }
    
    /**
     * Displays a list of all tags, and all files that have those
     * tags.
     * Called by the user with the "list" command.
     *
     * @param tagDict The hash table of tags to output.
     */
    void Operations::displayListOfTags(std::unordered_map<std::string,
            std::vector<std::string>> tagDict) {
        for (auto tag : tagDict) {
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
    void Operations::displayHelp(void) {
        std::string helpText =
                "tiger is a program for tagging and organizing files.\n"
                "Alternate between specifying tags and files in your\n"
                "arguments by using -t and -f, respectively.\n"
                "Commands:\n"
                "\thelp: Display this screen.\n"
                "\tadd: Add tag(s) to file(s).\n"
                "\tremove: Remove tag(s) from file(s).\n"
                "\tsearch: Look up files with a certain tag.\n"
                "\tlist: Display all tags on your system, and all\n"
                "\t\tof the files they are attached to.\n";
        
        std::cout << helpText;
    }
}
