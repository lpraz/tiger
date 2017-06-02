/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines tiger's helper functions, which don't fit neatly into any
 * classes used by tiger.
 * Any helper functions will be placed in the Tiger::Helpers namespace.
 */

// Stdlib includes
#include <iostream>

// Include self
#include "helpers.hpp"

namespace Tiger {
    namespace Helpers {
        /**
         * Converts a C-style list of command-line arguments to a vector.
         *
         * @param argumentCount The number of command-line arguments to
         *                      convert (or, the length of
         *                      argumentValues to convert all arguments).
         * @param argumentValues An array containing command-line arguments.
         */
        std::vector<std::string> convertArguments (int argumentCount,
                char *argumentValues[]) {
            std::vector<std::string> arguments;
            
            for (int index = 0; index < argumentCount; index++)
                arguments.push_back(argumentValues[index]);
            
            return arguments;
        }
        
        /**
         * Displays the help for the application and its commands.
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
