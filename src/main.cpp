/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Provides the top-level functions for tiger.
 */

// Stdlib includes
#include <string>
#include <unordered_map>
#include <vector>

// Cstdlib includes
#include <cstdio>

// POSIX-native includes
#include <unistd.h>

// Local includes
#include "Command.hpp"
#include "helpers.hpp"
#include "Operations.hpp"
#include "TagFile.hpp"

/**
 * Main method.
 * 
 * @param argumentCount The number of command-line arguments passed to
 *                      tiger.
 * @param argumentValues An array containing the command-line arguments
 *                       passed to tiger.
 * @return Exit code for the program (0 if successful exit).
 */

int main(int argumentCount, char *argumentValues[]) {
    // Get working dir
    // TODO: use std::filesystem::currentpath when C++17 is more available
    char workingDirCStr[FILENAME_MAX];
    getcwd(workingDirCStr, FILENAME_MAX);
    std::string workingDir(workingDirCStr);
    
    // Get tag file, hash table of tags from tag file
    Tiger::TagFile tagFile;
    std::unordered_map<std::string, std::vector<std::string>>& tagDict =
        tagFile.getTags();
    
    // Get arguments
    std::vector<std::string> arguments = Tiger::Helpers::convertArguments(
            argumentCount, argumentValues);
    
    // Convert arguments to Command object
    Tiger::Command command(arguments);
    
    // Act based on arguments
    switch (command.getAction()) {
        case Tiger::Command::Action::ADD:
            Tiger::Operations::addTags(tagDict, command.getTags(),
                    command.getFiles(), workingDir);
            tagFile.close();
            break;
        case Tiger::Command::Action::REMOVE:
            Tiger::Operations::removeTags(tagDict, command.getTags(),
                    command.getFiles(), workingDir);
            tagFile.close();
            break;
        case Tiger::Command::Action::SEARCH:
            Tiger::Operations::search(tagDict, command.getTags(),
                    command.getFiles());
            break;
        case Tiger::Command::Action::LIST:
            Tiger::Operations::displayListOfTags(tagDict);
            break;
        case Tiger::Command::Action::HELP:
        default:
            Tiger::Operations::displayHelp();
            break;
    }
    
    // Write changes to tag file, return OK exit code
    return 0;
}
