/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Provides the top-level functions for tiger.
 */

// TODO: Install Doxygen

// Stdlib includes
#include <string>
#include <unordered_map>
#include <vector>

// Local includes
#include "Command.hpp"
#include "helpers.hpp"
#include "operations.hpp"

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
    std::unordered_map<std::string, std::vector<std::string>> tags;
    
    // Get arguments
    std::vector<std::string> arguments = Tiger::Helpers::convertArguments(
            argumentCount, argumentValues);
    
    // Convert arguments to Command object
    Tiger::Command command(arguments);
    
    // Get tag file, save to hash table
    
    
    // Act based on arguments
    switch (command.getAction()) {
        case Tiger::Command::Action::TAG:
        case Tiger::Command::Action::SEARCH:
        case Tiger::Command::Action::LIST:
        case Tiger::Command::Action::HELP:
        default:
            Tiger::Operations::displayHelp();
    }
    
    // Return OK exit code
    return 0;
}
