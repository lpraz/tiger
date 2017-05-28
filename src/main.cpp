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
#include "helpers.hpp"

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
    
    // Get tag file
    
    
    // Act based on arguments
    
    
    // Return OK exit code
    return 0;
}
