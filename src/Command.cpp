/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines methods for the Command class.
 */

// Stdlib includes
#include <string>
#include <vector>

// Include own header
#include "Command.hpp"

namespace Tiger {
    /**
     * Constructs a Command given a vector of arguments.
     * Assumes the first argument will be the path to tiger's executable
     * file, the second is the "action" word (to be converted to an
     * Action in the newly-created Command), and all those thereafter
     * will be a combination of tags and file paths (toggled between with
     * -t and -f switches).
     * @param arguments A vector of arguments. Must be converted from
     * a C-style array of arguments, as is passed into the program
     * when run.
     */
    Command::Command(std::vector<std::string> arguments) {
        // Make an iterator of arguments, seek to action
        auto iter = arguments.begin();
        iter++;
        
        // Convert string to Action
        
        // Fill tags and files with remaining arguments
    }
}
