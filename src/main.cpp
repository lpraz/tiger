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
 * @return Exit code for the program (ideally 0).
 */

int main(int argumentCount, char *argumentValues[]) {
    // Get tag file, hash table of tags from tag file
    Tiger::TagFile tagFile;
    std::unordered_map<std::string, std::vector<std::string>>& tags =
        tagFile.getTags();
    
    // Get arguments
    std::vector<std::string> arguments = Tiger::Helpers::convertArguments(
            argumentCount, argumentValues);
    
    // Convert arguments to Command object
    Tiger::Command command(arguments);
    
    // Act based on arguments
    switch (command.getAction()) {
        case Tiger::Command::Action::ADD:
            Tiger::Operations::addTags(tags, command);
            break;
        case Tiger::Command::Action::REMOVE:
            Tiger::Operations::removeTags(tags, command);
            break;
        case Tiger::Command::Action::SEARCH:
            Tiger::Operations::search(tags, command);
            break;
        case Tiger::Command::Action::LIST:
            Tiger::Operations::displayListOfTags(tags);
            break;
        case Tiger::Command::Action::HELP:
        default:
            Tiger::Operations::displayHelp();
            break;
    }
    
    // Write changes to tag file, return OK exit code
    tagFile.close();
    return 0;
}
