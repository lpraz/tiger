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
            Tiger::Operations::add(tagDict, command.getTags(),
                    command.getFiles());
            tagFile.close();
            break;
        case Tiger::Command::Action::REMOVE:
            Tiger::Operations::remove(tagDict, command.getTags(),
                    command.getFiles());
            tagFile.close();
            break;
        case Tiger::Command::Action::SEARCH:
            Tiger::Operations::search(tagDict, command.getTags(),
                    command.getFiles());
            break;
        case Tiger::Command::Action::LIST:
            Tiger::Operations::list(tagDict);
            break;
        case Tiger::Command::Action::HELP:
        default:
            Tiger::Operations::help();
            break;
    }
    
    // Write changes to tag file, return OK exit code
    return 0;
}
