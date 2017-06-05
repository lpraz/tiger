/**
 * @file
 * @author lpraz
 *
 * @section DESCRIPTION
 * Defines tiger's helper functions, which don't fit neatly into any
 * classes used by tiger.
 * Any helper functions will be placed in the Tiger::Helpers namespace.
 */

// Include own header
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
    }
}
