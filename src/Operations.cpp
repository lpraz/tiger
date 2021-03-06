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
#include <sstream>

// Cstdlib includes
#include <cstdio>

// POSIX-native includes
#include <unistd.h>

// Local includes
#include "helpers.hpp"

// Include own header
#include "Operations.hpp"

namespace Tiger {
    /**
     * Converts a "short" file path to a full one, based on the program's
     * current working directory.
     *
     * @param shortPath The short file path. May also be a full one
     *                  (differentiated by a forward-slash at the
     *                  beginning, in which case no conversion is done).
     * @return The resulting full file path.
     */
    std::string Operations::toFullPath(std::string shortPath) {
        // Return shortPath if it's already a full path (starts with root)
        if (shortPath.at(0) == '/')
            return shortPath;
        
        // Otherwise, start by getting the current working directory
        // TODO: use std::filesystem::currentpath when C++17 is more available
        char workingDirCStr[FILENAME_MAX];
        getcwd(workingDirCStr, FILENAME_MAX);
        std::string workingDir(workingDirCStr);
        
        // Copy working directory into vector
        std::vector<std::string> fullPathVector;
        toVectorizedPath(workingDir, fullPathVector);
        
        // Then, copy the short path in
        toVectorizedPath(shortPath, fullPathVector);
        
        // Reconstruct the full path
        std::string fullPath;
        for (std::string subDir : fullPathVector)
            fullPath += "/" + subDir;
        
        return fullPath;
    }
    
    /**
     * Converts a file path as a string to a vector, containing the
     * subdirectories to take to the destination from the root
     * directory.
     *
     * @param path The file path, as a string.
     * @param The vector to copy the path into.
     */
    void Operations::toVectorizedPath(std::string path,
            std::vector<std::string>& pathVector) {
        std::istringstream pathStream(path);
        bool firstDir = true;
        
        while (pathStream.good()) {
            std::string nextSubDir = readSubDirectory(pathStream);
            
            if (nextSubDir == "..") {
                pathVector.pop_back();
            } else if (firstDir && nextSubDir == "~") {
                pathVector.clear();
                toVectorizedPath(getenv("HOME"), pathVector);
            } else if (nextSubDir != ".") {
                pathVector.push_back(nextSubDir);
            }
            
            if (firstDir == true)
                firstDir = false;
        }
    }
    
    /**
     * Reads the next string in a stream starting at its current position
     * and ending at the next forward slash ('/') or the EOF. Whitespace
     * is not ignored, and if the string starts with a forward slash,
     * it will be excluded.
     * @param stream The stream to read from.
     * @returns The string that was read.
     */
    std::string Operations::readSubDirectory(std::istream& stream) {
        stream >> std::noskipws;
        std::stringstream resultStream;
        char nextChar;
        bool firstChar(true);
        
        while (stream >> nextChar) {
            if (nextChar == '/' && !firstChar)
                break;
            
            if (nextChar != '/')
                resultStream << nextChar;
            
            if (stream.eof())
                break;
            
            firstChar = false;
        }
        
        return resultStream.str();
    }
    
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
        std::string fullFile(toFullPath(file));
        
        if (tagDict.find(tag) == tagDict.end()) {
            tagDict.insert({tag, std::vector<std::string> {fullFile}});
        } else {
            auto filePosition = std::find(tagDict[tag].begin(),
                    tagDict[tag].end(), fullFile);
            if (filePosition == tagDict[tag].end())
                tagDict[tag].push_back(fullFile);
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
        std::string fullFile(toFullPath(file));
        
        if (tagDict.find(tag) != tagDict.end()) {
            auto index = std::remove(tagDict[tag].begin(),
                    tagDict[tag].end(), fullFile);
            
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
    void Operations::add(std::unordered_map<std::string,
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
    void Operations::remove(std::unordered_map<std::string,
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
        if (tags.size() > 0) {
            std::cout << "=== Tags ===\n";
            for (auto tag : tags) {
                std::cout << tag << ":";
                auto tagFiles = tagDict.find(tag);
                
                if (tagFiles != tagDict.end())
                    for (auto tagFile = tagFiles->second.begin();
                            tagFile != tagFiles->second.end(); tagFile++)
                        std::cout << "\n\t" << *tagFile;
            }
        }
        
        if (files.size() > 0) {
            if (tags.size() > 0)
                std::cout << "\n\n";
            
            std::cout << "=== Files ===\n";
            for (auto file : files) {
                std::string fullFile(toFullPath(file));
                std::cout << fullFile << ":";
                
                for (auto tag : tagDict)
                    if (std::find(tag.second.begin(), tag.second.end(),
                            fullFile) != tag.second.end())
                        std::cout << "\n\t" << tag.first;
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
    void Operations::list(std::unordered_map<std::string,
            std::vector<std::string>> tagDict) {
        for (auto tag : tagDict) {
            std::cout << tag.first << ":\n\t";
            
            for (auto file = tag.second.begin();
                    file != tag.second.end(); file++) {
                if (file != tag.second.begin())
                    std::cout << "\n\t";
                
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
    void Operations::help(void) {
        std::string helpText =
                "tiger is a program for tagging and organizing files.\n"
                "Alternate between specifying tags and files in your\n"
                "arguments by using -t and -f, respectively.\n"
                "Commands:\n"
                "\thelp: Display this list.\n"
                "\tadd: Add tag(s) to file(s).\n"
                "\tremove: Remove tag(s) from file(s).\n"
                "\tsearch: Look up files with a certain tag.\n"
                "\tlist: Display all tags on your system, and all\n"
                "\t\tof the files they are attached to.\n";
        
        std::cout << helpText;
    }
}
